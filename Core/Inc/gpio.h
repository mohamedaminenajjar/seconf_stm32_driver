/*
 * gpio.h
 *
 *  Created on: Nov 16, 2024
 *      Author: Amine
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

//declare a struct for gpio, pin, mode, output_type, output_speed and resistor_type
typedef struct{
	unsigned int*  gpio;
	unsigned short pin;
	char           mode;
	char           output_type;
	char           output_speed;
	char           resistor_type;
}gpio_feature;


//define clock adress
#define RCC		(unsigned int *) 0x40023800


//define all GPIO
#define GPIOA	(unsigned int *) 0x40020000
#define GPIOB	(unsigned int *) 0x40020400
#define GPIOC	(unsigned int *) 0x40020800
#define GPIOD	(unsigned int *) 0x40020C00
#define GPIOE	(unsigned int *) 0x40021000
#define GPIOF	(unsigned int *) 0x40021400
#define GPIOG	(unsigned int *) 0x40021800
#define GPIOH	(unsigned int *) 0x40021C00
#define GPIOI	(unsigned int *) 0x40022000
#define GPIOJ	(unsigned int *) 0x40022400
#define GPIOK	(unsigned int *) 0x40022800


//define clock register
#define AHB1RSTR	0x10
#define AHB1ENR		0x30


//define all register
#define MODER	0x00
#define OTYPER	0x04
#define OSPEEDR	0x08
#define	PUPDR	0x0C
#define IDR		0x10
#define ODR		0x14
#define BSRR	0x18
#define LCKR	0x1C
#define AFRL	0x20
#define AFRH	0x24


//define GPIO FOR SHIFT
#define GPIOA_SHIFT		0x00
#define GPIOB_SHIFT		0x01
#define GPIOC_SHIFT		0x02
#define GPIOD_SHIFT		0x03
#define GPIOE_SHIFT		0x04
#define GPIOF_SHIFT		0x05
#define GPIOG_SHIFT		0x06
#define GPIOH_SHIFT		0x07
#define GPIOI_SHIFT		0x08
#define GPIOJ_SHIFT		0x09


//define all pins
#define PIN0	00
#define PIN1	01
#define PIN2	02
#define PIN3	03
#define PIN4	04
#define PIN5	05
#define PIN6	06
#define PIN7	07
#define PIN8	08
#define PIN9	09
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15


//define all modes
#define INPUT	0x00
#define OUTPUT	0x01
#define AL	    0x02
#define ANALOG	0x03


//define output type
#define PP	0x00
#define OD	0x01


//define output speed
#define LOW		0x00
#define MEDUIM	0x01
#define HIGH	0x02
#define VH		0x03

//define type of resistor
#define NP	0X00
#define PD	0X01
#define PU	0X02

//define bit state
#define BIT_SET			1
#define BIT_RESET		0


//function prototype
void GPIO_clock_Enable(unsigned int* gpio);
void GPIO_DeInit(unsigned int* gpio);
void GPIO_Init(gpio_feature* gpio_feat);
unsigned char GPIO_ReadInputDataBit(gpio_feature* gpio_feat);
unsigned short int GPIO_ReadInputData(gpio_feature* gpio_feat);
void GPIO_WriteBit(gpio_feature* gpio_feat, unsigned char bit_val);
void GPIO_Write(gpio_feature* gpio_feat, unsigned short por_val);


#endif /* INC_GPIO_H_ */
