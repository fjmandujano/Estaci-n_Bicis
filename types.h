/*------------------------------------------------------------------------------
  "THE BEER-WARE LICENSE" (Revision 42):
  <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
  can do whatever you want with this stuff. If we meet some day, and you think
  this stuff is worth it, you can buy me a beer in return to Hotboards crew
  (Beer-ware license created by Poul-Henning Kamp)

  \file       types.h
  \author     Mauricio Capistran
  \email      mauricio.capistrangarza@gmail.com
  \ver        1.0
  \date       Sept 4, 2014
  \target     Generic
  \brief      Header file used to redefine the variable types and several
              standard macros.
              Warning: this file should (must) not contain compiler-native
              macros, if needed, they should (must) be added in a separate file.
 -----------------------------------------------------------------------------*/

#ifndef TYPES_H
#define	TYPES_H

#include <pic18f4431.h>

/**-----------------------------------------------------------------------------
  \brief Redefinition of types
------------------------------------------------------------------------------*/
typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned long           u32;
typedef signed char             s8;
typedef signed short            s16;
typedef signed long             s32;

/**-----------------------------------------------------------------------------
  \brief    Bit Manipulation (u8 types)
------------------------------------------------------------------------------*/
#define SET_8BIT(var, bit)          ((var) |=  (u8)((u8)1<<(u8)(bit)))
#define CLEAR_8BIT(var, bit)        ((var) &= ~(u8)((u8)1<<(u8)(bit)))
#define QUERY_8BIT(var, bit)        ((_bool)((var)>>(u8)(bit)) & ((u8)1))
#define TOGGLE_8BIT(var, bit)       ((var) ^=  (u8)((u8)1<<(u8)(bit)))

/**-----------------------------------------------------------------------------
  \brief    Bit Manipulation (u16 types)
------------------------------------------------------------------------------*/
#define SET_16BIT(var, bit)         ((var) |=  (u16)((u16)1<<(u16)(bit)))
#define CLEAR_16BIT(var, bit)       ((var) &= ~(u16)((u16)1<<(u16)(bit)))
#define QUERY_16BIT(var, bit)       ((_bool)((var)>>(u16)(bit)) & ((u16)1))
#define TOGGLE_16BIT(var, bit)      ((var) ^=  (u16)((u16)1<<(u16)(bit)))

/**-----------------------------------------------------------------------------
  \brief    Bit Manipulation  (u32 types)
------------------------------------------------------------------------------*/
#define SET_32BIT(var, bit)         ((var) |=  (u32)((u32)1<<(u32)(bit)))
#define CLEAR_32BIT(var, bit)       ((var) &= ~(u32)((u32)1<<(u32)(bit)))
#define QUERY_32BIT(var, bit)       ((_bool)((var)>>(u32)(bit)) & ((u32)1))
#define TOGGLE_32BIT(var, bit)      ((var) ^=  (u32)((u32)1<<(u32)(bit)))

/**-----------------------------------------------------------------------------
  \brief    Shift left or right a variable a numer of fixed positions (u8 types)
------------------------------------------------------------------------------*/
#define LEFT_8SHIFT(var, pos)             ((var) <<= (u8)(pos))
#define RIGHT_8SHIFT(var, pos)            ((var) >>= (u8)(pos))

/**-----------------------------------------------------------------------------
  \brief    Shift left or right a variable a numer of fixed positions (u16 types)
------------------------------------------------------------------------------*/
#define LEFT_16SHIFT(var, pos)            ((var) <<= (u16)(pos))
#define RIGHT_16SHIFT(var, pos)           ((var) >>= (u16)(pos))

/**-----------------------------------------------------------------------------
  \brief    Shift left or right a variable a numer of fixed positions (u32 types)
------------------------------------------------------------------------------*/
#define LEFT_32SHIFT(var, pos)            ((var) <<= (u32)(pos))
#define RIGHT_32SHIFT(var, pos)           ((var) >>= (u32)(pos))


/**-----------------------------------------------------------------------------
  \brief Pin values
------------------------------------------------------------------------------*/
#define _HIGH                             1u
#define _LOW                              0u

/**-----------------------------------------------------------------------------
  \brief Error values
------------------------------------------------------------------------------*/
#define _ERROR                            0u
#define _SUCCES                           1u

/**-----------------------------------------------------------------------------
  \brief Boolean values
------------------------------------------------------------------------------*/
#define _TRUE                             (_bool)1
#define _FALSE                            (_bool)0


#endif	/* TYPES_H */

