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

void write_eeprom1(char address, char data);
char read_eeprom1(char address); 




#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */
