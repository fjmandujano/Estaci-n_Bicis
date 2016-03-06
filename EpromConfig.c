/*
 * File:   main.c
 * Author: Livier
 *
 * Created on 4 de marzo de 2016, 10:36 AM
 */


#include <xc.h>
#include "bitconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <P18F4431.h>

//prototypes
//void write_eeprom1(char address, char data);
//char read_eeprom1(char address);

/*
void main(void){
    
    char valorOffset,a1;
    for (a1=0;a1<16;a1++)
    write_eeprom1(a1,a1);
    for (a1=0;a1<16;a1++) {
    valorOffset = read_eeprom1(a1);
    return;
}*/

void write_eeprom1(char address, char data)
{
EEADR = address;
EEDATA = data;
EECON1bits.WREN = 1; // habilito escritura
//INTCONbits.GIE = 0; // desabilito las interrupciones
EECON2 = 0x55; // destrabo escritura
EECON2 = 0xAA;  //destrabo escritura
EECON1bits.WR = 1; // habilito escritura
//INTCONbits.GIE = 1; // habilito la interrupcion
EECON1bits.WREN = 0; // desabilito escritura
while (EECON1bits.WR); // espero hasta que WR se haga 0 por hard
}

char read_eeprom1(char address)
{
    EEADR = address;
    EECON1bits.EEPGD = 0x00;
    EECON1bits.CFGS = 0x00;
    EECON1bits.RD = 1 ;
    return EEDATA;
}


