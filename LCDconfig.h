/*
 * File:   LCD_Config.h
 * Author: JavierMandujano
 *
 * Created on 1 de abril de 2015, 13:41
 */

#ifndef LCD_CONFIG_H
#define	LCD_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


void config(void);
void write_LCD(u8 comando, u8 dato[]);
void LCD_init(void);
void write_Direction_LCD(u8 direcciones[], u8 datos[]);
void config_interrupt(void);
void LCD_write_2Lines(u8 mensaje_L1[], u8 mensaje_L2[]);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_CONFIG_H */

