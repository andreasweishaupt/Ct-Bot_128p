/*******************************************************************************
*
* File Name:   maus.h
* Project  :   c't Bot library
*
*
* Ver.     Date                 Author                    Comments
* -------  ----------   ---------------------   ------------------------------
* 2.00	   28.06.2006   Yang Li & Xingxing Hu   build
*                                               Überträgt ein Byte an den Sensor -> maus_writeByte(int data);
*                                               Liest ein Byte vom Sensor -> maus_readByte(void);
*                                               Überträgt ein write-Kommando an den Sensor -> maus_write(int adr, int data);
*                                               Schickt ein Lesekommando an den Sensor und liest ein Byte zurück -> maus_read(unsigned int adr);
*                                               maus init -> maus_init(void);
*                                               
*												                                              
* 2006 Institut für Informatik, Tu-Clausthal
*****************************************************************************/
/***************************************************************************
*
*the maus source is based on mouse.c ver 1.0 by Benjamin Benz 20.12.05 
*Copyright (c) 2005, 59 Temple Place, Suite 330, Boston,MA 02111-1307, USA.
*
****************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 ***************************************************************************/
 
#ifndef MAUS_H_
#define MAUS_H_

#include <avr/io.h>
#include "ena.h"


#define MOUSE_CONFIG_REG			0x00 /*!< Reset, Power Down, Forced Awake, etc */
#define MOUSE_DELTA_Y_REG			0x02 /*!< Y Movement */
#define MOUSE_DELTA_X_REG			0x03 /*!< X Movement */
#define MOUSE_CFG_RESET				0x80 /*!< Reset Circuit */
#define MOUSE_CFG_POWERDOWN			0x40 /*!< Power Down analog Circuit */
#define MOUSE_CFG_FORCEAWAKE		0x01 /*!< Keep Sensor awake */
#define MOUSE_MAX_PIXEL_REG			0x05 /*!< Maximum Pixel value in current frame.*/
#define MOUSE_MIN_PIXEL_REG			0x06 /*!< Minimum Pixel value in current frame.*/
#define MOUSE_PIXEL_SUM_REG			0x07 /*!< This register is used to find the average pixel value.*/
#define MOUSE_PIXEL_DATA_REG		0x08 /*!< Actual picture of surface */

unsigned int mousePicture[18*18];


/* Überträgt ein Byte an den Sensor */
void maus_writeByte(int data);

/* Liest ein Byte vom Sensor */
int maus_readByte(void);

/* Überträgt ein write-Kommando an den Sensor */
void maus_write(int adr, int data);

/* Schickt ein Lesekommando an den Sensor und liest ein Byte zurück */
int maus_read(unsigned int adr);

/* maus init*/
void maus_init(void);

#endif