# STM32 GPIO Control Project 🚀
This project provides a basic GPIO driver for STM32 microcontrollers, allowing configuration and control of GPIO pins on various ports (A to K) of the STM32F407 Discovery board. 🛠️
## Project Structure 📁
- **main.c**: The main program that initializes and controls GPIO pins.
- **gpio.c**: Implementation of GPIO initialization, read, and write functions.
- **gpio.h**: Header file for GPIO function declarations and macro definitions.
## Files 📂
### main.c
This is the entry point of the project. It contains the main function where the GPIO pins are initialized and controlled.
### gpio.c
This file includes the implementation of the following functions:
- `GPIO_ClockEnable(unsigned int * gpio_x)`: Enables the clock for the specified GPIO port.
- `GPIO_DeInit(unsigned int * gpio_x)`: Deinitializes the GPIO port.
- `GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)`: Configures the GPIO port.
- `GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)`: Reads the specified input port pin.
- `GPIO_ReadInputData(unsigned int * gpio_x)`: Reads the specified GPIO input data port.
- `GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal)`: Sets or clears the selected data port bit.
- `GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)`: Writes data to the specified GPIO data port.
### gpio.h
This header file contains the function prototypes and necessary macro definitions used in `gpio.c`.
## How to Use 📋
1. Clone this repository to your local machine.
2. Open the project in your preferred IDE (e.g., STM32CubeIDE).
3. Compile and upload the code to your STM32F407 Discovery board.
4. Observe the behavior of the GPIO pins as per the implementation in `main.c`.
## Contributing 🤝
Contributions are welcome! Feel free to open issues or submit pull requests.
## License 📜
This project is licensed under the MIT License. See the LICENSE file for more details.
## Contact 📧
For any questions or inquiries, please contact:
- Email: [mohamedamine.najjar@isimg.tn]([https://www.linkedin.com/in/mohamed-amine-najjar-2808a726b/](https://mail.google.com/mail/u/0/?fs=1&tf=cm&source=mailto&to=mohamedamine.najjar@isimg.tn))
- LinkedIn: [Mohamed Amine Najjar](https://www.linkedin.com/in/mohamed-amine-najjar-2808a726b/)
---
Happy coding! 😊
