/*
  =============================================================================
 * Name		:EXTI_Private.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_

/* EXTI Base Address 0x4001 3C00 */
#define EXTI_BASE_ADDRESS (0x40013C00)
#define EXTI_OFFSET      (0x00)

/* System Configuration Base Address */
#define SYSCFG_BASE_ADDRESS (0x40013C00)
#define SYSCFG_EXTICR_OFFSET (0x08)
/**
 * @brief   : This struct contain EXTI registers 
 * 
 */
typedef struct 
{
    u32 IMR;      /* Interrupt mask register */
    u32 EMR;      /* Event mask register */
    u32 RTSR;     /* Rising trigger selection register */
    u32 FTSR;     /* Falling trigger selection register */
    u32 SWIER;    /* Software interrupt event register */
    u32 PR;       /* Pending register set by HW when interrupt is triggered & clear by SW at the beginning of the handler  */

}EXTI_t;

typedef struct 
{
    u32 EXTICR[4];  /* SYSCFG external interrupt configuration register */
}SYSCFG_t;

/* EXTI registers  */
#define EXTI_REG ((volatile EXTI_t*) (EXTI_BASE_ADDRESS + EXTI_OFFSET))

/* System Configuration Registers */
#define SYSCFG_REG ((volatile SYSCFG_t*) (SYSCFG_BASE_ADDRESS + SYSCFG_EXTICR_OFFSET))

#define EXTI_GPIOA (0b0000)
#define EXTI_GPIOB (0b0001)
#define EXTI_GPIOC (0b0010)

#define EXTI_GPIOx_MASK (0b1111)

#endif /* MCAL_EXTI_PRIVATE_H_ */
