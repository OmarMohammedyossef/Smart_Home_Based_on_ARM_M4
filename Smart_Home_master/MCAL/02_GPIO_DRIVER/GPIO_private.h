/*
  =============================================================================
 * Name		:GPIO_priivate.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

     /*file guards*/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define LCKK                   16
     /* base addresses for GPIO*/
#define GPIO_BASE_ADDRESS      0X40020000

#define RCC_AHB1RSTR             *((volatile u32*)(0x40023810))
#define RCC_AHB1ENR              *((volatile u32*)(0x40023830))

typedef enum {
	GPIO_MODER,
	GPIO_OTYPER,
	GPIO_OSPEEDR,
	GPIO_PUPDR,
	GPIO_IDR,
	GPIO_ODR,
	GPIO_BSRR,
	GPIO_LCKR,
	GPIO_AFRL,
	GPIO_AFRH
}registers_names;
/*
 #define GPIOA_BASE_ADDRESS              0x40020000
 #define GPIOB_BASE_ADDRESS              0x40020400
 #define GPIOC_BASE_ADDRESS              0x40020800
 #define GPIOD_BASE_ADDRESS              0x40020C00
 #define GPIOE_BASE_ADDRESS              0x40021000
 #define GPIOH_BASE_ADDRESS              0x40021C00



typedef struct {
	volatile u32    MODER;
	volatile u32	OTYPER;
	volatile u32	OSPEEDR;
	volatile u32	PUPDR;
	volatile u32	IDR;
	volatile u32	ODR;
	volatile u32	BSRR;
	volatile u32	LCKR;
	volatile u32	AFRL;
	volatile u32	AFRH;
}GPIO_MemMap_type;

#define GPIOA        ((GPIO_MemMap_type *) (GPIOA_BASE_ADDRESS))
#define GPIOB        ((GPIO_MemMap_type *) (GPIOB_BASE_ADDRESS))
#define GPIOC        ((GPIO_MemMap_type *) (GPIOC_BASE_ADDRESS))
#define GPIOD        ((GPIO_MemMap_type *) (GPIOD_BASE_ADDRESS))
#define GPIOE        ((GPIO_MemMap_type *) (GPIOE_BASE_ADDRESS))
#define GPIOH        ((GPIO_MemMap_type *) (GPIOH_BASE_ADDRESS))*/

/*struct contain registers for each GPIOx */
typedef struct {

volatile u32 GPIO_registers[1802];

}GPIO_MemMap_type;

    /* define pointer to struct GPIO_MemMap_type for each GPIOx*/
#define GPIO        ((GPIO_MemMap_type *) (GPIO_BASE_ADDRESS))


#endif /* GPIO_PRIVATE_H_ */
