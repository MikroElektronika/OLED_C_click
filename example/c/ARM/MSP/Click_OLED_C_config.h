#include "Click_OLED_C_types.h"


const uint32_t _OLEDC_SPI_CFG[ 7 ] = 
{ 
        _SPI_MASTER, 
        2,
        _SPI_CLOCKSOURCE_SMCLK, 
        _SPI_MSB_FIRST, 
        _SPI_PHASE_DATA_CHANGE_FIRST_CAPTURE_NEXT, 
        _SPI_CLK_IDLE_HIGH, 
        _SPI_3PIN 
};