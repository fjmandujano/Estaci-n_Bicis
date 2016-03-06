/*
 * File:   Utilities.h
 * Author: JavierMandujano
 *
 * Created on 24 de febrero de 2015, 20:07
 */

#include "types.h"

#ifndef UTILITIES_H
#define	UTILITIES_H

#ifdef	__cplusplus
extern "C" {
#endif



void delay(u16 time);
u8 PowerON(u8 power, u8 valStep);
u8 check_lugar(u16 data[]);



#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */

