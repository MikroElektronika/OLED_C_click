/*
Example for OLED_C Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI module and AN pin, RST pin, CS pin, PWM pin and INT pin  as output
- Application Initialization - Initializes driver init and OLED C init and sets full screen on white color with writting demo text.
- Application Task - (code snippet) -
      1. Display demo rectangle
      2. Display demo line
      3. Display demo Image


*/

#include "Click_OLED_C_types.h"
#include "Click_OLED_C_config.h"
#include "fonts.h"
#include "pictures.h"

uint8_t new_contrast = 0;
uint8_t text1[7] = {'H','e','l','l','o',',',0};
uint8_t text2[17] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','d','e','m','o',0};
uint8_t text3[17] = {'f','o','r',' ','O','L','E','D',' ','C',' ','c','l','i','c','k',0};
void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_OLEDC_SPI_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    oledc_spiDriverInit( (T_OLEDC_P)&_MIKROBUS1_GPIO, (T_OLEDC_P)&_MIKROBUS1_SPI );
    oledc_init();
    oledc_fill_screen( 0xFFFF );

    oledc_set_font( &guiFont_Tahoma_8_Regular[0], 0, _OLEDC_FO_HORIZONTAL );
    oledc_text( &text1[0], 15, 10 );
    oledc_text( &text2[0], 5, 30 );
    oledc_text( &text3[0], 5, 45 );
    Delay_ms( 1000 );

}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}