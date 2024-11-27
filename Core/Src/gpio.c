/*
 * gpio.c
 *
 *  Created on: Nov 16, 2024
 *      Author: Amine
 */
#include "gpio.h"

/**
  * @brief  Enable the clock the gpio peripheral registers .
  * @param  gpio: where can be (GPIOA..GPIOI) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_clock_Enable(unsigned int * gpio)
{
	if(gpio == GPIOA)
	{
		//activate the clock for GPIOA
		*(RCC + AHB1ENR) |= (0x1 << GPIOA_SHIFT);
	}
	if(gpio == GPIOB)
	{
		//activate the clock for GPIOB
		*(RCC + AHB1ENR) |= (0x1 << GPIOB_SHIFT);
	}
	if(gpio == GPIOC)
	{
		//activate the clock for GPIOC
		*(RCC + AHB1ENR) |= (0x1 << GPIOC_SHIFT);
	}
	if(gpio == GPIOD)
	{
		//activate the clock for GPIOD
		*(RCC + AHB1ENR) |= (0x1 << GPIOD_SHIFT);
	}
	if(gpio == GPIOE)
	{
		//activate the clock for GPIOE
		*(RCC + AHB1ENR) |= (0x1 << GPIOE_SHIFT);
	}
	if(gpio == GPIOF)
	{
		//activate the clock for GPIOF
		*(RCC + AHB1ENR) |= (0x1 << GPIOF_SHIFT);
	}
	if(gpio == GPIOG)
	{
		//activate the clock for GPIOG
		*(RCC + AHB1ENR) |= (0x1 << GPIOG_SHIFT);
	}
	if(gpio == GPIOH)
	{
		//activate the clock for GPIOH
		*(RCC + AHB1ENR) |= (0x1 << GPIOH_SHIFT);
	}
	if(gpio == GPIOI)
	{
		//activate the clock for GPIOI
		*(RCC + AHB1ENR) |= (0x1 << GPIOI_SHIFT);
	}
}

/**
  * @brief  Deinitializes the gpio peripheral registers to their default reset values.
  * @param  gpio: where can be (GPIOA..GPIOI) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DeInit(unsigned int* gpio)
{
	if(gpio == GPIOA)
	{
		//reset the gpioA
		*(RCC + AHB1RSTR) |= (0x1 << GPIOA_SHIFT);
		//set the gpioA
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOA_SHIFT);
	}
	if(gpio == GPIOB)
	{
		//reset the gpioB
		*(RCC + AHB1RSTR) |= (0x1 << GPIOB_SHIFT);
		//set the gpioB
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOB_SHIFT);
	}
	if(gpio == GPIOC)
	{
		//reset the gpioc
		*(RCC + AHB1RSTR) |= (0x1 << GPIOC_SHIFT);
		//set the gpioc
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOC_SHIFT);
	}
	if(gpio == GPIOD)
	{
		//reset the gpioD
		*(RCC + AHB1RSTR) |= (0x1 << GPIOD_SHIFT);
		//set the gpioD
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOD_SHIFT);
	}
	if(gpio == GPIOE)
	{
		//reset the gpioE
		*(RCC + AHB1RSTR) |= (0x1 << GPIOE_SHIFT);
		//set the gpioE
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOE_SHIFT);
	}
	if(gpio == GPIOF)
	{
		//reset the gpioF
		*(RCC + AHB1RSTR) |= (0x1 << GPIOF_SHIFT);
		//set the gpioF
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOF_SHIFT);
	}
	if(gpio == GPIOG)
	{
		//reset the gpioG
		*(RCC + AHB1RSTR) |= (0x1 << GPIOG_SHIFT);
		//set the gpioJ
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOG_SHIFT);
	}
	if(gpio == GPIOH)
	{
		//reset the gpioH
		*(RCC + AHB1RSTR) |= (0x1 << GPIOH_SHIFT);
		//set the gpioH
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOH_SHIFT);
	}
	if(gpio == GPIOI)
	{
		//reset the gpioI
		*(RCC + AHB1RSTR) |= (0x1 << GPIOI_SHIFT);
		//set the gpioI
		*(RCC + AHB1RSTR) &= ~(0x1 << GPIOI_SHIFT);
	}
}


/**
  * @brief  Initialize the gpio peripheral register.
  * @param  gpio_feat: where is a pointer to gpio_feature struct that contain gpio, pin, mode, output_type, output_speed, resistor_type.
  * @retval None
  */
void GPIO_Init(gpio_feature* gpio_feat)
{
	unsigned int mask=0;
	//set the moder register to choice (input, output, alternate function or analog) according to the choice of the user
	mask = ~(0x03 << gpio_feat->pin *2);
	*(gpio_feat->gpio +MODER) &= mask;
	*(gpio_feat->gpio +MODER) |= (gpio_feat->mode << (gpio_feat->pin *2) );
	//set the otyper register to choice (push pull or open drain) according to the choice of the user
	mask = ~(0x01 << gpio_feat->pin);
	*(gpio_feat->gpio +OTYPER) &= mask;
	*(gpio_feat->gpio +OTYPER) |= (gpio_feat->output_type << gpio_feat->pin);
	//set the ospeedr register to choice (low, medium, high, very high) according to the choice of the user
	mask = ~(0x03 << (gpio_feat->pin *2) );
	*(gpio_feat->gpio +OSPEEDR) &= mask;
	*(gpio_feat->gpio +OSPEEDR) |= (gpio_feat->output_speed << (gpio_feat->pin *2) );
	//set the pupdr register to choice (nopull, pulldown, pullup) according to the choice of the user
	mask = ~(0x03 << (gpio_feat->pin *2) );
	*(gpio_feat->gpio +PUPDR) &= mask;
	*(gpio_feat->gpio +PUPDR) |= (gpio_feat->resistor_type << (gpio_feat->pin *2) );
}


/**
  * @brief  Reads the specified input port pin.
  * @param  gpio_feat: where is a pointer to gpio_feature struct that contain gpio, pin, mode, output_type, output_speed, resistor_type.
  * @retval The input port pin value.
  */
unsigned char GPIO_ReadInputDataBit(gpio_feature* gpio_feat)
{
	unsigned char bit_val = *(gpio_feat->gpio + IDR) &  (0x1 << gpio_feat->pin );
	if( 1 == bit_val )
	{
		return 1;
	}
	return 0;
}


/**
  * @brief  Reads the specified GPIO input data port.
  * @param  gpio: where can be (GPIOA..GPIOI) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
unsigned short int GPIO_ReadInputData(gpio_feature* gpio_feat)
{
  return *(gpio_feat->gpio + IDR);
}


/**
  * @brief  Sets or clears the selected data port bit.
  * @brief  Deinitializes the gpio peripheral registers to their default reset values.
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(gpio_feature* gpio_feat, unsigned char bit_val)
{
	unsigned int mask = ~(0x01 << gpio_feat->pin );
	*(gpio_feat->gpio + ODR) &= mask;
	*(gpio_feat->gpio + ODR) |= bit_val << gpio_feat->pin;
}


/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  gpio_feat: where is a pointer to gpio_feature struct that contain gpio, pin, mode, output_type, output_speed, resistor_type.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(gpio_feature* gpio_feat, unsigned short por_val)
{
	unsigned int mask = ~( 0xFFFF );
	*(gpio_feat->gpio + ODR) &= mask;
	*(gpio_feat->gpio + ODR) |= por_val;
}
