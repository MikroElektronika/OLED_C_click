/*
    __oledc_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __oledc_driver.h
@brief    OLED_C Driver
@mainpage OLED_C Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   OLEDC
@brief      OLED_C Click Driver
@{

| Global Library Prefix | **OLEDC** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"
#include "stdbool.h"

#ifndef _OLEDC_H_
#define _OLEDC_H_

/** 
 * @macro T_OLEDC_P
 * @brief Driver Abstract type 
 */
#define T_OLEDC_P    const uint8_t*

/** @defgroup OLEDC_COMPILE Compilation Config */              /** @{ */

   #define   __OLEDC_DRV_SPI__                            /**<     @macro __OLEDC_DRV_SPI__  @brief SPI driver selector */
//  #define   __OLEDC_DRV_I2C__                            /**<     @macro __OLEDC_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __OLEDC_DRV_UART__                           /**<     @macro __OLEDC_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup OLEDC_VAR Variables */                           /** @{ */

///@}
/**
 * @name                 Font Direction
 ******************************************************************************/
///@{
extern const uint8_t  _OLEDC_FO_HORIZONTAL;
extern const uint8_t  _OLEDC_FO_VERTICAL;
extern const uint8_t  _OLEDC_FO_VERTICAL_COLUMN;

/**
 * @name                 Remamp set
 ******************************************************************************/
///@{
extern const uint8_t _OLEDC_RMP_INC_HOR;
extern const uint8_t _OLEDC_RMP_INC_VER;
extern const uint8_t _OLEDC_RMP_COLOR_NOR;
extern const uint8_t _OLEDC_RMP_COLOR_REV;
extern const uint8_t _OLEDC_RMP_SEQ_RGB;
extern const uint8_t _OLEDC_RMP_SEQ_BGR;
extern const uint8_t _OLEDC_RMP_SCAN_NOR;
extern const uint8_t _OLEDC_RMP_SCAN_REV;
extern const uint8_t _OLEDC_RMP_SPLIT_DISABLE;
extern const uint8_t _OLEDC_RMP_SPLIT_ENABLE;
extern const uint8_t _OLEDC_COLOR_65K;
extern const uint8_t _OLEDC_COLOR_262K;
extern const uint8_t _OLED_C_IMG_HEAD;

/**
 * @name                 Device Properties
 ******************************************************************************/
///@{
extern const uint8_t  _OLEDC_SCREEN_WIDTH;
extern const uint8_t  _OLEDC_SCREEN_HEIGHT;
extern const uint16_t _OLEDC_SCREEN_SIZE;  
extern const uint8_t  _OLEDC_ROW_OFF;
extern const uint8_t  _OLEDC_COL_OFF;

///@}
/**
 * @name                 SSD1355 Commands
 ******************************************************************************/
///@{
extern const uint8_t  _OLEDC_SET_COL_ADDRESS;
extern const uint8_t  _OLEDC_SET_ROW_ADDRESS;
extern const uint8_t  _OLEDC_WRITE_RAM;
extern const uint8_t  _OLEDC_READ_RAM;
extern const uint8_t  _OLEDC_SET_REMAP;
extern const uint8_t  _OLEDC_SET_START_LINE;
extern const uint8_t  _OLEDC_SET_OFFSET;
extern const uint8_t  _OLEDC_MODE_OFF;
extern const uint8_t  _OLEDC_MODE_ON;
extern const uint8_t  _OLEDC_MODE_NORMAL;
extern const uint8_t  _OLEDC_MODE_INVERSE;
extern const uint8_t  _OLEDC_FUNCTION;
extern const uint8_t  _OLEDC_SLEEP_ON;
extern const uint8_t  _OLEDC_SLEEP_OFF;
extern const uint8_t  _OLED_C_NOP;
extern const uint8_t  _OLED_C_SET_RESET_PRECH;
extern const uint8_t  _OLED_C_ENHANCEMENT;
extern const uint8_t  _OLEDC_CLOCK_DIV;
extern const uint8_t  _OLEDC_VSL;
extern const uint8_t  _OLEDC_GPIO;
extern const uint8_t  _OLEDC_SETSEC_PRECH;
extern const uint8_t  _OLEDC_GREY_SCALE;
extern const uint8_t  _OLEDC_LUT;
extern const uint8_t  _OLEDC_PRECH_VOL;
extern const uint8_t  _OLEDC_VCOMH;
extern const uint8_t  _OLEDC_CONTRAST;
extern const uint8_t  _OLEDC_MASTER_CONTRAST;
extern const uint8_t  _OLEDC_MUX_RATIO;
extern const uint8_t  _OLEDC_COMMAND_LOCK;
extern const uint8_t  _OLEDC_SCROLL_HOR;
extern const uint8_t  _OLEDC_START_MOV;
extern const uint8_t  _OLEDC_STOP_MOV;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OLEDC_INIT Driver Initialization */              /** @{ */

#ifdef   __OLEDC_DRV_SPI__
void oledc_spiDriverInit(T_OLEDC_P gpioObj, T_OLEDC_P spiObj);
#endif
#ifdef   __OLEDC_DRV_I2C__
void oledc_i2cDriverInit(T_OLEDC_P gpioObj, T_OLEDC_P i2cObj, uint8_t slave);
#endif
#ifdef   __OLEDC_DRV_UART__
void oledc_uartDriverInit(T_OLEDC_P gpioObj, T_OLEDC_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void oledc_gpioDriverInit(T_OLEDC_P gpioObj);
       
                                                                /** @} */
                                                                                                                                
/** @defgroup OLEDC_FUNC Driver Functions */                   /** @{ */

/**
 * @brief OLED C Initialization
 *
 * Function initializes function pointers and perform setup of the SSD1351
 * must be called first
 */
void oledc_init( void );

/**
 * @brief OLED C Hardware Reset
 *
 * Performs hardware reset of the click board. Init function calling executin
 * of this function.
 */
void oledc_reset( void );

/**
 * @brief OLED C Enable
 *
 * @param[in] state ( 1 ON / 0 OFF )
 *
 * Enable or disable the display usinf EN pin on the clickboard.
 */
void oledc_enable( uint8_t state );

/**
 * @brief OLED C Command
 *
 * @param[in] command   valid command
 * @param[in] args      pointer to command argument
 * @param[in] args_len  arguments size in bytes
 *
 * Executes provided comman.
 */
void oledc_command( uint8_t command, uint8_t *args, uint16_t args_len );

/**
 * @brief OLED C Fill Scren
 *
 * @param[in] color     RGB color
 *
 * Fills whole screen with provided color.
 */
void oledc_fill_screen( uint16_t color );

/**
 * @brief OLED C Draw Rectangle
 *
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 * @param[in] col_end   column end offset also counted from the left border
 * @param[in] row_end   row offset also counted from the top border
 * @param[in] color     RGB color
 *
 * Function allows you to draw retcangles which can be used to draw lines
 * clean specific regions of the screen.
 */
void oledc_rectangle( uint8_t col_off, uint8_t row_off,
                       uint8_t col_end, uint8_t row_end, uint16_t color );

/**
 * @brief OLED C Draw BMP Image
 *
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 * @param[in] img       pointer to bmp image
 *
 * Function draws image on the screen. Provided image must be in .bmp format
 * with 6 bytes header size. Providing image of any other format may result in
 * unpredictable behaviour.
 */
void oledc_image( const uint8_t *img, uint8_t column_off, uint8_t row_off );

/**
 * @brief OLED C Draw Text
 *
 * @param[in] text      text string
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 *
 * Function writes text on the screen.
 */
void oledc_text( uint8_t *text, uint16_t col_off, uint16_t row_off );

/**
 * @brief OLED C Font Setup
 *
 * @param[in] font          pointer to font definition
 * @param[in] color         text color
 * @param[in] orientation   text orientation
 *
 * Function setup the parameters needed for @c oled_c_text. Before first usage
 * of @c oled_c_text it is needed to call this function and setup all
 * parameters.
 */
void oledc_set_font( const uint8_t *font, uint16_t color, uint8_t orientation );





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_OLED_C_STM.c
    @example Click_OLED_C_TIVA.c
    @example Click_OLED_C_CEC.c
    @example Click_OLED_C_KINETIS.c
    @example Click_OLED_C_MSP.c
    @example Click_OLED_C_PIC.c
    @example Click_OLED_C_PIC32.c
    @example Click_OLED_C_DSPIC.c
    @example Click_OLED_C_AVR.c
    @example Click_OLED_C_FT90x.c
    @example Click_OLED_C_STM.mbas
    @example Click_OLED_C_TIVA.mbas
    @example Click_OLED_C_CEC.mbas
    @example Click_OLED_C_KINETIS.mbas
    @example Click_OLED_C_MSP.mbas
    @example Click_OLED_C_PIC.mbas
    @example Click_OLED_C_PIC32.mbas
    @example Click_OLED_C_DSPIC.mbas
    @example Click_OLED_C_AVR.mbas
    @example Click_OLED_C_FT90x.mbas
    @example Click_OLED_C_STM.mpas
    @example Click_OLED_C_TIVA.mpas
    @example Click_OLED_C_CEC.mpas
    @example Click_OLED_C_KINETIS.mpas
    @example Click_OLED_C_MSP.mpas
    @example Click_OLED_C_PIC.mpas
    @example Click_OLED_C_PIC32.mpas
    @example Click_OLED_C_DSPIC.mpas
    @example Click_OLED_C_AVR.mpas
    @example Click_OLED_C_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __oledc_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */