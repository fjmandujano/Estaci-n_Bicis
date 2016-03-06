/* 
 * File:   LCD_main.c
 * Author: JavierMandujano
 *
 * Created on 5 de marzo de 2016, 12:50
 */

#include <pic18f4431.h>
#include "BitConfig.h"
#include "types.h"
#include "LCDconfig.h"
#include "utilities.h"
#include <math.h>
#include <string.h>
//#include "EpromConfig.h"

void write_eeprom1(char address, char data);
char read_eeprom1(char address);

//Bits del RS y del Enable de la pantalla LCD
#define RS LATCbits.LATC4
#define Enable LATCbits.LATC5

//Bit que verifica si el sistema tiene energía
#define powerON PORTAbits.RA4
u16 data_lugar[] = {10, 10, 10, 10, 0, 10};
u8 direcciones_memoria[] = {10, 20, 30, 40, 50, 60};

//Mensajes de la pantalla
u8 Error1[] = {"  Sistema fuera "};
u8 Error2[] = {"   de servicio  "};
u8 MENSAJE_L1[] = {"   Bienvenido!  "};
u8 MENSAJE_L2[] = {"    Buen dia!   "};
u8 BiciRecibida1[] = {"Bici casilla: "};
u8 BiciRecibida2[] = {"Poner Credencial"};


void main()
{
    u8 step = 0, temp = 0, nextStep = 0, lugar_activado[] = "0", credencial = 0, lugar = 10; 
    //configuracion inicial
    config();
    //inicializar la LCD    
    LCD_init();


    while(1)
    {
        switch(step)
        {
            case 0: //Verificar que el sitema esté energizado
                
                //Si el sistema está energizado
                nextStep = 1;
                //TRISAbits.RA4=1;
                //u8 A=PORTAbits.RA4;
                step = PowerON(powerON, nextStep);
                if(step == 0)
                {
                    LCD_write_2Lines(Error1 ,Error2 );
                }
               
                break;
            
            case 1:
                LCD_write_2Lines(MENSAJE_L1 ,MENSAJE_L2);
                //Verificar que si algún seguro se activó
                //Funcion chear sensor límite seguros
                lugar_activado[0] = check_lugar(data_lugar)+0x30;
                nextStep = 2;
                step = PowerON(powerON, nextStep);
                if(lugar_activado != 0)
                {
                    strcat(BiciRecibida1,lugar_activado);
                    LCD_write_2Lines(BiciRecibida1,BiciRecibida2);
                    lugar_activado[0] =lugar_activado[0]-0x30; 
                    //Esperara a que se coloque una credencial
                    
                    
                    //Pantalla lugar asignado
                    
                    
                    //ir al caso 2
                    
                }
                //Verificar si se colocó una credencial
                else
                {
                    //Funcion que lee la información del lector de RFID
                    
                    //Si se lee una credencial
                    credencial = 12; //cuando se tenga la función de leer RFID se cambiará el numero
                    //lugar = direcciones_memoria[lugar_activado[0]-1]; 
                    write_eeprom1(lugar, credencial);
                    nextStep = 3;
                
                }
                step = PowerON(powerON, nextStep);
                if(step == 0)
                {
                    LCD_write_2Lines(Error1 ,Error2 );
                }
                //función seguro activado
                break;   
            case 2:
                
                
                
                //Asignar matricula/nomina a lugar en estación de bici
                break;
                
            case 3:
                //Verificar que la credencial tenga asigndado un lugar
                
                
                //si no tiene lugar asignado
                
                //Pantalla Credencial no Asignada
                
               //Si tiene lugar asignado
                
                //Pantalla con el lugar de la bici
                
                //Desactivar seguro
                
                break;
                
        }         
    }
}



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
