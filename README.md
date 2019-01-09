![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# OLED_C Click

- **CIC Prefix**  : OLEDC
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Jan 2018.

---


### Software Support

We provide a library for the OLED_C Click on our [LibStock](https://libstock.mikroe.com/projects/view/1117/oled-c-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines SPI bus driver and drivers that offer a choice for writting data in registers and reading data
from registers. Library includes functions for drawing a picture, pulls a rectangle and writes text on the screen.
The user can set the desired font text, and adjust the background color.

Key functions :

- ``` void oledc_init( void ) ``` - Functions for initializes chip
- ``` void oledc_text( uint8_t *text, uint16_t col_off, uint16_t row_off ) ``` - Function writes text on the screen
- ``` void oledc_image( const uint8_t *img, uint8_t column_off, uint8_t row_off ) ``` - Function draws image on the screen

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI module and AN pin, RST pin, CS pin, PWM pin and INT pin  as output
- Application Initialization - Initializes driver init and OLED C init and sets full screen on white color with writting demo text.
- Application Task - (code snippet) -
      1. Display demo rectangle
      2. Display demo line
      3. Display demo Image


```.c
void applicationTask()
{
    oledc_fill_screen( 0xFFFF );
    Delay_100ms();

    /* Rectangle demo*/
    oledc_rectangle( 0, 0, 96, 96, 0xF000 );
    Delay_ms( 500 );
    oledc_rectangle( 5, 5, 91, 91, 0xFF00 );
    Delay_ms( 500 );
    oledc_rectangle( 10, 10, 86, 86, 0x00F0 );
    Delay_ms( 500 );
    oledc_rectangle( 15, 15, 81, 81, 0x0F0F );
    Delay_ms( 500 );
    oledc_rectangle( 20, 20, 76, 76, 0xF000 );
    Delay_ms( 500 );
    oledc_rectangle( 25, 25, 71, 71, 0xFF00 );
    Delay_100ms();

    /* Line demo */
    oledc_rectangle( 25, 25, 71, 27, 0 );
    Delay_100ms();
    oledc_rectangle( 25, 71, 71, 73, 0 );
    Delay_100ms();
    oledc_rectangle( 25, 25, 27, 71, 0 );
    Delay_100ms();
    oledc_rectangle( 68, 25, 71, 71, 0 );
    Delay_ms( 3000 );


    /* Image demo */
    oledc_image( &me_logo_bmp[0], 0, 0 );
    Delay_ms( 2000 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1117/oled-c-click) page.

Other mikroE Libraries used in the example:

- Conversions
- SPI


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
