#include <pic18f4431.h>
#include "utilities.h"
#include "types.h"
//#include "i2c.h"


#define RS LATCbits.LATC4 //4
#define Enable LATCbits.LATC5

u8 i, j, flagConfig, flagDir; //mover a la capa de writeLCD

u8 COMMAND_CONFIG[]={0x33, 0x32, 0x28, 0x0F, 0}; //secuencia de inicialización
u8 MENSAJE_L1[] = {"   Bienvenido!  "};
u8 MENSAJE_L2[] = {"    Buen dia!   "};

u8 Salto[] = {192,0};
u8 Home[] = {128,0};

void config(void)
{
    OSCCON=0x73;
    T0CON=0b11000000;   //configurar el timer, se va a usar el oscilador interno  y un prescaler de 2
    //ADCON1 = 0b00001110;
    ANSEL0 = 0;
    TRISB = 0b00100000;
    TRISA = 0b00010000;
    TRISC = 0b00000000;
    TRISD = 0b00000100;
    //configurar el Timer2 para las interrupciones para dar cada paso
    //T2CON = 0b00000000;
    //PR2 = 200;

    delay(10);
    //u8 dato = 0,oldDirection, oldVoltaje, Voltaje;
    PORTA = 0;

    //config I2C
    //CloseI2C_ahr(); //close i2c if was operating earlier
    //Configurar_Master( MASTER);
 }

u8 write_LCD(u8 comando, u8 dato[])
{
    u8 send,temp;

    if(comando == 0) //RS = 0, comando de la pantalla
    {
        RS = comando;
        Enable = 1;
        send = dato[i]>>4;
        //send = send*2;
        //send = send*4;
        //temp = PORTA;
        //temp &= 0b11110000;
        //PORTA = send | temp;
        PORTA = send;//*2;
        delay(10);
        Enable = 0;
        delay(10);

        RS = comando;
        Enable = 1;
        send = dato[i]&(0x0F);
        //send = send*2;
        //send = send*4;
        //temp = PORTA;
        //temp &= 0b11110000;
        //PORTA = send | temp;
        PORTA = send;//*2;
        delay(10);
        Enable = 0;
        delay(10);
    }
    else
    {
        RS = comando;
        Enable = 1;
        send = dato[i]>>4;
        //send = send*2;  //comentado ahorita
        //send = send*4;
        //temp = PORTA;
        //temp &= 0b11110000;
        //PORTA = send | temp;
        PORTA = send; //send*2; //comentado ahorita
        delay(1);
        Enable = 0;
        delay(1);

        RS = comando;
        Enable = 1;
        send = dato[i]&(0x0F);
        //send = send*2;  //comentado ahorita
        //send = send*4;
        //temp = PORTA;
        //temp &= 0b11110000;
        PORTA = send; //send*2; //comentado ahorita
        delay(1);
        Enable = 0;
        delay(1);
    }
    i++;
    if(dato[i] == 0)
    {
        flagConfig = 1;
        i = 0;
    }

}

void LCD_init(void)
{
    flagConfig = 0;
  while(flagConfig == 0){
        write_LCD(0, COMMAND_CONFIG);
    }
    flagConfig = 0;

    while(flagConfig == 0){
        write_LCD(1, MENSAJE_L1);
    }
    flagConfig = 0;
    //salto de linea
    while(flagConfig == 0){
        write_LCD(0, Salto);
    }
    flagConfig = 0;
    //escribir un mensaje
    while(flagConfig == 0){
        write_LCD(1, MENSAJE_L2);
    }
}

void LCD_write_2Lines(u8 mensaje_L1[], u8 mensaje_L2[])
{
    PORTA = 0;
    flagConfig = 0;

    while(flagConfig == 0){
        write_LCD(0, Home);
    }
    flagConfig = 0;

    while(flagConfig == 0){
        write_LCD(1,  mensaje_L1);
    }
    flagConfig = 0;
    //salto de linea
    while(flagConfig == 0){
        write_LCD(0, Salto);
    }
    flagConfig = 0;
    //escribir un mensaje
    while(flagConfig == 0){
        write_LCD(1, mensaje_L2);
    }
}

void write_Direction_LCD(u8 direcciones[], u8 datos[])
{

    u8 direccion, send;
    //colocar el cursor donde en la direccion deseada
        RS = 0;
        Enable = 1;
        send = direcciones[i]>>4;
        send = send*2;
        PORTA = send*2;
        delay(10);
        Enable = 0;
        delay(10);

        RS = 0;
        Enable = 1;
        send = direcciones[i]&(0x0F);
        send = send*2;
        PORTA = send*2;
        delay(10);
        Enable = 0;
        delay(10);

    //escribir el valor acorde a la posicion
        RS = 1;
        Enable = 1;
        send = datos[i]>>4;
        send = send*2;
        PORTA = send*2;
        delay(10);
        Enable = 0;
        delay(10);

        RS = 1;
        Enable = 1;
        send = datos[i]&(0x0F);
        send = send*2;
        PORTA = send*2;
        delay(10);
        Enable = 0;
        delay(10);

        i++;

    if(direcciones[i] == 0)
    {
        flagDir = 1;
        i = 0;
    }
}
