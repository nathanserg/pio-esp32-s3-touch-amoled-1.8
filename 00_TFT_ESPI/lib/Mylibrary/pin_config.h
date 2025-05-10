#pragma once

#define XPOWERS_CHIP_AXP2101

#define LCD_SDIO0 4
#define LCD_SDIO1 5
#define LCD_SDIO2 6
#define LCD_SDIO3 7
#define LCD_SCLK 11
#define LCD_CS 12
#define LCD_WIDTH 368
#define LCD_HEIGHT 448

// TOUCH
#define IIC_SDA 15
#define IIC_SCL 14
#define TP_INT 21

// ES8311
#define I2S_MCK_IO 16
#define I2S_BCK_IO 9
#define I2S_DI_IO 10
#define I2S_WS_IO 45
#define I2S_DO_IO 8


#define MCLKPIN             16
#define BCLKPIN              9
#define WSPIN               45
#define DOPIN               10
#define DIPIN                8
#define PA                  46

// SD
const int SDMMC_CLK = 2;
const int SDMMC_CMD = 1;
const int SDMMC_DATA = 3;

/* 
#pragma once

#define XPOWERS_CHIP_AXP2101

#define LCD_USB_QSPI_DRIVER   1

#define SEND_BUF_SIZE         (0x1000) //(LCD_WIDTH * LCD_HEIGHT + 8) / 10

#define SPI_FREQUENCY         8000000
#define TFT_SPI_MODE          SPI_MODE0
#define TFT_SPI_HOST          SPI2_HOST

#define TFT_QSPI_D0 4
#define TFT_QSPI_D1 5
#define TFT_QSPI_D2 6
#define TFT_QSPI_D3 7
#define TFT_QSPI_SCK 11
#define TFT_CS 12
#define TFT_DC 17  // random unused pin
#define TFT_RES 18 // random unused pin
#define TFT_WIDTH 368
#define TFT_HEIGHT 448

// TOUCH
#define IIC_SDA 15
#define IIC_SCL 14
#define TP_INT 21

// ES8311
#define I2S_MCK_IO 16
#define I2S_BCK_IO 9
#define I2S_DI_IO 10
#define I2S_WS_IO 45
#define I2S_DO_IO 8


#define MCLKPIN             16
#define BCLKPIN              9
#define WSPIN               45
#define DOPIN               10
#define DIPIN                8
#define PA                  46

// SD
const int SDMMC_CLK = 2;
const int SDMMC_CMD = 1;
const int SDMMC_DATA = 3; */