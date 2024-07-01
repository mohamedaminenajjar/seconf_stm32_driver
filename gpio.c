/**
  ******************************************************************************
  * @file    stm32-gpio-driver/gpio.c
  * @author  Mohamed Amine Najjar
  * @mail    mohamedamine.najjar@isimg.tn
  * @Tel     (+216) 51 134 079
  * @version V1.0.0
  * @date    20-03-2024
  *****************************************************************************
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

// Add define for RCC clock 
volatile unsigned short int *AHB1ENR = (unsigned short int*)(0x40023800 + 0x30);

// Add define for RCC reset 
volatile unsigned short int *AHB1RSTR = (unsigned short int*)(0x40023800 + 0x10);

/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable(unsigned int * gpio_x)
{
  if (gpio_x == GPIO_A)
  {
    // Enable the clock for GPIOA 
    *AHB1ENR |= (1<<0);
  }
  else if (gpio_x == GPIO_B)
  {
    // Enable the clock for GPIOB 
    *AHB1ENR |= (1<<1);
  }
  else if (gpio_x == GPIO_C)
  {
    // Enable the clock for GPIOC 
    *AHB1ENR |= (1<<2);
  }
  else if (gpio_x == GPIO_D)
  {
    // Enable the clock for GPIOD 
    *AHB1ENR |= (1<<3);
  }
  else if (gpio_x == GPIO_E)
  {
    // Enable the clock for GPIOE 
    *AHB1ENR |= (1<<4);
  }
  else if (gpio_x == GPIO_F)
  {
    // Enable the clock for GPIOF 
    *AHB1ENR |= (1<<5);
  }
  else if (gpio_x == GPIO_G)
  {
    // Enable the clock for GPIOG 
    *AHB1ENR |= (1<<6);
  }
  else if (gpio_x == GPIO_H)
  {
    // Enable the clock for GPIOH 
    *AHB1ENR |= (1<<7);
  }
  else if (gpio_x == GPIO_I)
  {
    // Enable the clock for GPIOI 
    *AHB1ENR |= (1<<8);
  }
}

/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DeInit(unsigned int * gpio_x)
{
  if (gpio_x == GPIO_A)
  {
    // Activate the forced reset for GPIOA 
    *AHB1RSTR |= (1<<0);
    
    // Deactivate the forced reset for GPIOA 
    *AHB1RSTR &= ~(1<<0);
  }
  else if (gpio_x == GPIO_B)
  {
    // Activate the forced reset for GPIOB 
    *AHB1RSTR |= (1<<1);
    
    // Deactivate the forced reset for GPIOB 
    *AHB1RSTR &= ~(1<<1);
  }
  else if (gpio_x == GPIO_C)
  {
    // Activate the forced reset for GPIOC 
    *AHB1RSTR |= (1<<2);
    
    // Deactivate the forced reset for GPIOC 
    *AHB1RSTR &= ~(1<<2);
  }
  else if (gpio_x == GPIO_D)
  {
    // Activate the forced reset for GPIOD 
    *AHB1RSTR |= (1<<3);
    
    // Deactivate the forced reset for GPIOD 
    *AHB1RSTR &= ~(1<<3);
  }
}

/**
  * @brief  Configure the gpio_x
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  Mode: can be INPUT, OUTPUT, AF or AN
  * @param  typeOutput: can be PP or OD
  * @param  pin: can be 0...15
  * @retval None
  */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
  // Determine the mask value for MODER and prepare the configuration for the MODER register
  unsigned int mask = ~(0x3 << (pin * 2)); // Create a 2-bit mask (00)
 
  // Configure the MODER register
  *(gpio_x + MODER) &= mask; // Force the two bits of MODER for the pin with the two 0 bits in the mask
  *(gpio_x + MODER) |= (Mode << (pin * 2)); // Force the two bits of MODER for the pin with the mode
  
  // Determine the mask value for PP and prepare the configuration for the PP register
  mask = ~(0x1 << pin);
  if (typeOutput == PP)
  {
    *(gpio_x + OTYPER) &= mask;
  }
  else
  {
    *(gpio_x + OTYPER) |= ~mask;
  }
  
  // Configure the mode PP
  // ...   
}

/**
  * @brief  Reads the specified input port pin.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)
{
  // Check if the BitVal != 0x0
  unsigned char BitVal = 0x00;
  // Test if the pin value is != 0x00
  if ((*(gpio_x + IDR) & (GPIO_Pin)) != 0x00)
  {
    // Return 1
    BitVal = 0x1;
  }
  // Otherwise, test if the pin value is == 0x00
  else
  {
    // Return 0
    BitVal = 0x00;
  }
  return BitVal;
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x)
{
  return *(gpio_x + IDR);
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal)
{
  // Check if BitVal != 0x0
  if (BitVal != 0x0)
    // Set the value to 1
    *(gpio_x + ODR) |= GPIO_Pin;
  // Otherwise, set the value to 0
  else
    *(gpio_x + ODR) &= ~(GPIO_Pin);
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)
{
  *(gpio_x + ODR) |= (0xFFFF << 0);
}

/******************* (C) COPYRIGHT 2024 Mohamed Amine Najjar *****END OF FILE*******************/

