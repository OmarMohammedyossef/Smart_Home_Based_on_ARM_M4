/*
  =============================================================================
 * Name		:EEPROM_int.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

#ifndef EEPROM_EEPROM_INT_H_
#define EEPROM_EEPROM_INT_H_


void H_EEPROM_void_Init(void);
/*
 *   H_EEPROM_u8_WriteByte is used to write 1 byte data to EEPROM address
 *   inputs : Address , data
 *   output : true in case of success , false in case of fail
 */
u8 H_EEPROM_u8_WriteByte(u16 copy_u16Add , u8 copy_u8Byte);
u8 H_EEPROM_u8_ReadByte(u16 copy_u16Add ,u8 * ptr);
#endif /* EEPROM_EEPROM_INT_H_ */
