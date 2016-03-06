#include <pic18f4431.h>
#include "types.h"
#include "LCDconfig.h"
#include "utilities.h"

//Entradas Sensores de límite
#define SensorSeguro1 PORTBbits.RB0
#define SensorSeguro2 PORTBbits.RB1
#define SensorSeguro3 PORTBbits.RB2
#define SensorSeguro4 PORTBbits.RB3
#define SensorSeguro5 PORTBbits.RB4
#define SensorSeguro6 PORTBbits.RB5

 u8 bici = 0;//  PORTBbits.RB5<<5+PORTBbits.RB4<<4+PORTBbits.RB3<<3+PORTBbits.RB2<<2+PORTBbits.RB1<<1+PORTBbits.RB0;

//wirteValue copia los valores de una variable o puerto y la escribe en otro, sin sobreescribir algun bit de la variable destino, garantizando así que la informacion no se vea modificada o que se generen pérdidas de información
/**
u8 writeValue(u8 originalValue, u8 newValue, u8 numBitsToChange){
    unsigned char newVal;
    unsigned char mask;

    mask = 0xFF>>(8 - numBitsToChange); //se crea una máscara de tamaño del numero de bits indicado
    originalValue &= ~mask; //Se copian los valores de los bits mas significativos del valor original, el número de bits guardados depende del número indicado en los parámetros de la función
    newValue &= mask;       //Se guardan los valores de los bits menos significativos de la variable a modificar
    newVal = originalValue | newValue; //Se guardan los valores modificados de los 4 bits menos significativos y los sin modificar de los mas significativos
    return newVal;  //Se regresa el valor ya modificado, sin los 4 bits mas significativos sin modificar

}
*/

//Función que recibe un valor y genera un retraso de tiempo en base a ese valor, cabe mencionar que la base de tiempo de esta función es de 100us
//Por lo que si se quiere un retraso de 1ms, el valor de time debe ser de 10.
void delay(u16 time)
{
    u16 value; //Declaramos una variable local para la resta
    value=time; //se iguala da el valor deseado para la cuenta a la variable local
    do{
        TMR0L=156; //Se inicia el contador del timer en 136, haciendo que el overflow sea al contar 120
        do{}while(INTCONbits.TMR0IF==0); //mientras la bandera de overflow no se acive seguir contando
        INTCONbits.TMR0IF = 0;    //reinicar la bandera de overflow del timer al activarse
    }
    while(--value!= 0);  //Restar un 1 al valor deseado para contar
}


u8 PowerON(u8 power, u8 valStep)
{
    u8 step = 0;
    if (power == 1)
    {
        step = valStep;
    }
    else
    {
        step = 0;
    }
    return step;
}

u8 check_lugar(u16 data[])
{
    bici =  PORTBbits.RB5<<5+PORTBbits.RB4<<4+PORTBbits.RB3<<3+PORTBbits.RB2<<2+PORTBbits.RB1<<1+PORTBbits.RB0;
    for(u8 i = 0; i < 6; i++)
    {
        if((bici>>i)%2==0 && data[i]==0)//data[i] == 0 && seguros[i] == 0)
        {
            return i+1;
        }
    }
    return 0;
}