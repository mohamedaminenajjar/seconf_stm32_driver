/**
  ******************************************************************************
  * @file    stm32-gpio-driver/gpio.h
  * @author  Mohamed Amine Najjar
  * @mail    mohamedamine.najjar@isimg.tn
  * @Tel     (+216) 51 134 079
  * @version V1.0.0
  * @date    20-03-2024
  *****************************************************************************

/* Includes ------------------------------------------------------------------*/
/** 
  * @brief General Purpose I/O
  */

#define GPIO_A (unsigned int *)  (0x40020000)
// terminer pour les autres gpios  
#define GPIO_B (unsigned int *)  (0x40020400)
#define GPIO_C (unsigned int *)  (0x40020800)
#define GPIO_D (unsigned int *)  (0x40020C00)
#define GPIO_E (unsigned int *)  (0x40021000)
#define GPIO_F (unsigned int *)  (0x40021400)
#define GPIO_G (unsigned int *)  (0x40021800)
#define GPIO_H (unsigned int *)  (0x40021C00)
#define GPIO_I (unsigned int *)  (0x40022000)
#define GPIO_J (unsigned int *)  (0x40022400)
#define GPIO_K (unsigned int *)  (0x40022800)


/* Register location */
#define MODER                       0x00
// terminer pour les autres registers
#define OTYPER                      0x01
#define OSPEEDR                     0x02 
#define PUPDR                       0x03
#define IDR                         0x04
#define ODR                         0x05
#define BSRR                        0x06
#define LCKR                        0x07
#define AFRL                        0x08
#define AFRH                        0x09

/* Pin Number */
#define Pin0                       00
// terminer pour les autres pins
#define Pin1                       01
#define Pin2                       02
#define Pin3                       03
#define Pin4                       04
#define Pin5                       05
#define Pin6                       06
#define Pin7                       07
#define Pin8                       08
#define Pin9                       09
#define Pin10                      10
#define Pin11                      11
#define Pin12                      12
#define Pin13                      13
#define Pin14                      14
#define Pin15                      15



/* Mode */
#define INPUT                       0x00
// terminer pour les autres modes
#define OUTPUT                      0x01
#define AL                          0x02
#define AN                          0x03

/* typeOutput */
#define PP                          0x00
// terminer pour le autre Type
#define OD                          0x01

/* GPIO Init structure definition */
/** @defgroup GPIO_pins_define */
#define GPIO_Pin_0                 ((unsigned short)0x0001)  /* Pin 0 selected */
// terminer pour les autres pins
#define GPIO_Pin_1                 (unsigned short)0x0002
#define GPIO_Pin_2                 (unsigned short)0x0004
#define GPIO_Pin_3                 ((unsigned short)0x0008
#define GPIO_Pin_4                 (unsigned short)0x0010
#define GPIO_Pin_5                 (unsigned short)0x0020
#define GPIO_Pin_6                 (unsigned short)0x0040
#define GPIO_Pin_7                 (unsigned short)0x0080
#define GPIO_Pin_8                 (unsigned short)0x0100
#define GPIO_Pin_9                 (unsigned short)0x0200
#define GPIO_Pin_10                (unsigned short)0x0400
#define GPIO_Pin_11                (unsigned short)0x0800
#define GPIO_Pin_12                (unsigned short)0x1000
#define GPIO_Pin_13                 (unsigned short)0x2000
#define GPIO_Pin_14                 (unsigned short)0x4000
#define GPIO_Pin_15                 (unsigned short)0x8000

/* -----------------ajouter les protopyes des fonctions----------------------*/


/* GPIO enable function */
void GPIO_ClockEnable (unsigned int * gpio_x);

/* GPIO Resete function */
void GPIO_DeInit(unsigned int * gpio_x);

/* Config function */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);

/* Read functions */
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin);
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x);

/* Write functions */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal);
/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/