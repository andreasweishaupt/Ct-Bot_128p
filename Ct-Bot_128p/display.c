/*
 * display.c
 *
 * Created: 19.01.2018 12:07:28
 *  Author: Andreas
 */ 

#include "display.h"

int x,j;

static char puffer[PUFFER_GROESSE];	/*string fuer Displayausgaben */

void write_data(char data){ //ein Zeichen aus data in den Displayspeicher schreiben
        int i;
		
			for (x=0;x<100 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }
	   
	schieberegister_data_schicken(0x38,(1<<1),0x04);
	PORTC &= ~0x07;   // Alles zurück setzen ==> Fallende Flanke von Enable  portc &=~ 0x07 (&=~0b111)
	
	for (x=0;x<40 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }
		
	schieberegister_data_schicken(data,(1<<1),0x04|(1<<0));
		
		// Enable muss für mind. 450 ns High bleiben, bevor es fallen darf!
		// ==> Also mind. 8 Zyklen warten
        for (i=0; i<250; i++){
                asm("nop");
        }
      PORTC &= ~0x07;	
}
 
void befehl_schicken(unsigned char befehl){		//ein befehl an das Display senden
	unsigned char i;
	schieberegister_data_schicken(befehl,(1<<1),0x04);       /*SRCLK = PORTC.1 = 1 und RCLK=PC2=1*/
	
	for (i=0; i<100; i++){
	        asm("nop");
	}
	PORTC &= ~0x07;	
}


void cursor_position (int zeile, int spalte) {
   switch (zeile) {
    case 1:
		befehl_schicken(0x80 + spalte - 1);
		break;
    case 2:
		befehl_schicken(0xc0 + spalte - 1);
		break;
    case 3:
		befehl_schicken(0x94 + spalte - 1);
		break;
    case 4:
		befehl_schicken(0xd4 + spalte - 1);
		break;
    default: break;
   }
}

/*Schreibt einen String auf das Display.*/
void display_ausgabe(char *format, ...) {
	
	unsigned int zeichen = 0;
	va_list	args;
	
	/* Sicher gehen, das der zur Verfuegung stehende Puffer nicht
	 * ueberschrieben wird.
	 */
	va_start(args, format);
	vsnprintf(puffer, PUFFER_GROESSE, format, args);
	va_end(args);
	
	/* Ausgeben bis Puffer leer ist */
	while(puffer[zeichen] != '\0') {
		write_data(puffer[zeichen]);
		zeichen++;
	}	
	return;
}

/* Init Display */
void display_init(void)
{
	schieberegister_init();

	DDRC |= 0x07;		// Ausgänge
	DDRC &= ~(1<<5);		// Eingänge   DISPLAY_IN =(1<<5)	/*!< Input-Pins Display */

	for (x=0;x<100 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }
	   
	// Register in 8-Bit-Modus 3x übertragen, dazwischen warten
	schieberegister_data_schicken(0x38,(1<<1),0x04);
	PORTC &= ~0x07;   
	
	for (x=0;x<40 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }
		
	schieberegister_data_schicken(0x38,(1<<1),0x04);
	PORTC &= ~0x07;   
	
	for (x=0;x<40 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }	
	   
	schieberegister_data_schicken(0x38,(1<<1),0x04);
	PORTC &= ~0x07;
	
	for (x=0;x<40 ;x++ )
       {
        for (j=0;j<100 ;j++ ){}
       }		
	
	befehl_schicken(0x0f);  		//Display On, Cursor On, Cursor Blink
	befehl_schicken(CLEAR); // Display löschen, Cursor Home
	
}