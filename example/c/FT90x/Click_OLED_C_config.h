#include "Click_OLED_C_types.h"

const uint32_t _OLEDC_SPI_CFG[ 3 ] = 
{ 
        _SPI_MASTER_CLK_RATIO_8,
        _SPI_CFG_POLARITY_IDLE_HIGH |
        _SPI_CFG_PHASE_CAPTURE_RISING | 
        _SPI_CFG_SS_AUTO_DISABLE | 
        _SPI_CFG_FIFO_DISABLE, 
        _SPI_SS_LINE_NONE 
};
