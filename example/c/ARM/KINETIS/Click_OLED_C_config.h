#include "Click_OLED_C_types.h"

const uint32_t _OLEDC_SPI_CFG[ 2 ] = 
{ 
        1000000,
        _SPI_CFG_CLK_PHASE_CAPT_LEADING | 
        _SPI_CFG_CLK_IDLE_LOW |
        _SPI_CFG_MASTER | 
        _SPI_CFG_MSB_FIRST |
        _SPI_CFG_FRAME_SIZE_8BITS | 
        _SPI_CFG_SELECT_CTAR0
};