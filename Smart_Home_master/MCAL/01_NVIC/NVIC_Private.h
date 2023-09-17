/*
  =============================================================================
 * Name		:NVIC_Private.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
#ifndef MCAL_NVIC_PRIVATE_H_
#define MCAL_NVIC_PRIVATE_H_

/* Base address for Nested Vector Interrupt Control (SCB) */
#define NVIC_BASE_ADDRESS (0xE000E100)

/* Base address for System Control and Block register (SCB) */
#define SCB_BASE_ADDRESS  (0xE000ED00)

/* Offset address of Application interrupt and reset control register (AIRCR)  */
#define AIRCR_OFFSET_ADDRESS (0x0C)

typedef struct {
    u32 ISER[7]; /* Interrupt set-enable register rs[Read/Set] */
    /**
     * @brief  Reserved registers ( look at ST M4 TRM core peripherals NVIC Register map )   
     * Reserved : From 0x11C0 to 0x180 The Diff is 0x64 (100 byte decimal) 
     * 100/4 == 25 4 byte registers are form 0x11C to 0x180 
     * but we delete 1 register because 0x180 is not included 
     * 
     */
    u32 RES1[24];
    u32 ICER[7];  /* Interrupt clear-enable register rc_w1[Read/clear by 1] */
    u32 RES2[24];
    u32 ISPR[7];  /* Interrupt set-pending register rs[Read/Set] */
    u32 RES3[24];
    u32 ICPR[7];  /* Interrupt clear-pending register rc_w1[Read/clear by 1] */
    u32 RES4[24];
    u32 IABR[7];  /* Interrupt active bit register r[Read only] */
    u32 RES5[24];
     /* Interrupt priority register ( Cortex m4 support 240 interrupt)
      so we need 240 register each on is 8-bit to set priority for each interrupt */
    u8  IPR[60 * 4];

}NVIC_t;

#define NVIC_REG ((volatile NVIC_t*) (NVIC_BASE_ADDRESS))

/* Application interrupt and reset control register */
#define AIRCR   (*((volatile u32*) SCB_BASE_ADDRESS + AIRCR_OFFSET_ADDRESS))

/* This is a key that you must write it in the upper bits [16:32] of AIRCR before accessing it */
#define VECTKEY  (0x5FA)

#define PRIORITY_GROUP_MASK (0x700) /* 0b00000000 00000000 00000111 00000000 */

/* 
#define GROUP4Bits_SUB0BITS (0b011)  
#define GROUP3Bits_SUB1BITS (0b100)  
#define GROUP2Bits_SUB2BITS (0b101)  
#define GROUP1Bits_SUB3BITS (0b110)  
#define GROUP0Bits_SUB4BITS (0b111)  
  */

#endif /* MCAL_NVIC_PRIVATE_H_ */
