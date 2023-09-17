/*
  =============================================================================
 * Name		:LCD_int.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "../../LIB/STD_datatypes.h"
void LCD_enuInit(void);

void LCD_enuWriteData(u8 Copy_u8Data);


void LCD_enuWriteCommand(u8 Copy_u8Command);

void LCD_enuSendString(const char * Copy_pcString);

void LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_SendNumber(s16 Num);
#endif /* LCD_INT_H_ */
