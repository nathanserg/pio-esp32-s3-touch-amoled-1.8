#include <Arduino.h>
//#include "sh8601.h"
#include <TFT_eSPI.h>       // Include the graphics library
#include "Arduino_DriveBus_Library.h"
#include "Arduino_GFX_Library.h"
#include "pin_config.h"
#include <Wire.h>
#include "HWCDC.h"

HWCDC USBSerial;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite1 = TFT_eSprite(&tft);
TFT_eSprite sprite2 = TFT_eSprite(&tft);

Arduino_DataBus *bus = new Arduino_ESP32QSPI(
  LCD_CS /* CS */, LCD_SCLK /* SCK */, LCD_SDIO0 /* SDIO0 */, LCD_SDIO1 /* SDIO1 */,
  LCD_SDIO2 /* SDIO2 */, LCD_SDIO3 /* SDIO3 */);

Arduino_GFX *gfx = new Arduino_SH8601(bus, -1 /* RST */,
                                      0 /* rotation */, false /* IPS */, LCD_WIDTH, LCD_HEIGHT);


//uint16_t *spriteBuffer = (uint16_t *)ps_malloc(368 * 448 * 2);  // Allocate in PSRAM


void draw()
{
sprite1.fillSprite(TFT_BLACK);
//sprite2.fillSprite(TFT_GREEN);
sprite1.drawString("Hello World",20,20,4);
sprite1.fillRect(10,100,60,60,TFT_RED);
sprite1.fillRect(80,100,60,60,TFT_GREEN);
sprite1.fillRect(150,100,60,60,TFT_BLUE);
 
 gfx->draw16bitRGBBitmap(0, 0, (uint16_t*)sprite1.getPointer(), 368, 448);
 //gfx->drawbitRGBBitmap(0, 68, (uint16_t*)sprite2.getPointer(), 368, 380);
 //gfx->fillRect(0,0,100,100,RED);
}

void memory()
{
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
}

void setup()
{
  // Init Display
  if (!gfx->begin()) {
    USBSerial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(BLACK);

  gfx->Display_Brightness(150);

  delay(3000);
  log_d("Before sprite");
  memory();
  sprite1.setSwapBytes(1);
  sprite1.setColorDepth(16);  // Ensure 16-bit color depth
  //sprite1.setBuffer(spriteBuffer, 368, 448);
  
  sprite1.createSprite(368, 448);
  // sprite1.
  //sprite2.createSprite(368, 380);
  log_d("After sprite");
  memory();

  delay(1000);
  draw();
  log_d("After draw");
  memory();
  delay(100);
}

void loop()
{
  draw();
  delay(50);
}