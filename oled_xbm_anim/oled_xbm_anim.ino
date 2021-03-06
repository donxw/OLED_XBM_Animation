/*
   OLED Animation Example
   Modified from code posted at:  https://www.hackster.io/138689/pixel-art-on-oled-display-7f8697#code
   GIMP used to create XBM files in frames.h
   
   This code is for educational and hobby purposes only.
   
   boards tested:  
      NodeMCU 1.0 for Heltec wifikit8 
      Heltec Wifi Kit 32
*/

#include <Wire.h> //I2C
#include <U8g2lib.h>
#include <AsyncDelay.h>
#include "frames.h"

AsyncDelay tick;

//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 5, /* data=*/ 4);  //heltek wifikit8
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);  //heltec wifikit32 page mode
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 15, /* data=*/ 4);  //heltec wifikit32
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 2, /* data=*/ 0);  //node mcu with D3 (gpio0) data and D4 (gpio2) on clk and no reset pin - page buffer

const int AnimationDelay = 400; // larger delay = slower frame animation
bool animation_direction = false;
int current_frame = 0;

void setup() {
  u8g2.begin();
  tick.start(AnimationDelay, AsyncDelay::MILLIS);

  #ifdef WIFI_Kit_32
  Wire.begin(4, 15);  //required for wifikit 32 only (breaks wifikit 8)
  Serial.print("wire.begin(4, 15) invoked");
#endif
}

void loop() {
  if (tick.isExpired()) {
    drawAnimation();
    if (animation_direction) {
      current_frame--;
    } else {
      current_frame++;
    }

    if (current_frame == 2) {
      animation_direction = true;
    }

    if (current_frame == 0) {
      animation_direction = false;
    }
    tick.repeat();
  }
}

void drawAnimation() {
  u8g2.firstPage();
  do {
    switch (current_frame) {
      case 0:
        //u8g2.drawXBMP(0, 0, frames_width, frames_height, testXbm0_bits);
        u8g2.drawXBMP(0, 0, frames_width, frames_height, blinkImg[0]);
        break;
      case 1:
        //u8g2.drawXBMP(0, 0, frames_width, frames_height, testXbm1_bits);
        u8g2.drawXBMP(0, 0, frames_width, frames_height, blinkImg[1]);
        break;
      case 2:
        //u8g2.drawXBMP(0, 0, frames_width, frames_height, testXbm2_bits);
        u8g2.drawXBMP(0, 0, frames_width, frames_height, blinkImg[2]);
        break;
    }
  } while ( u8g2.nextPage() );
}
