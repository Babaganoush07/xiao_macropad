#include "HID-Project.h"
#include <ezButton.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// OLED Object
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// create ezButton object that attach to pins
ezButton left(9);
ezButton center(8);
ezButton right(7);

// LampCar Logo setup
#define image_width 31
#define image_height 32
static const unsigned char image_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0x0F, 0x00, 0x00, 0xA8, 0x15, 0x00, 0x00, 0x04, 0x31, 0x00, 
  0x00, 0xF6, 0x67, 0x00, 0xE0, 0xFF, 0xFF, 0x03, 0xF0, 0xFF, 0xFF, 0x07, 
  0xF0, 0xFF, 0xFF, 0x0F, 0xF0, 0xFE, 0xBF, 0x0F, 0x78, 0xFE, 0x3F, 0x07, 
  0x40, 0x06, 0x31, 0x01, 0x80, 0x07, 0xE0, 0x01, 0x00, 0x80, 0x08, 0x00, 
  0x00, 0x80, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x60, 0x07, 0x00, 
  0x00, 0x98, 0x15, 0x00, 0x00, 0x50, 0x1A, 0x00, 0x00, 0xA8, 0x05, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

void setup() {
  // Setup OLED
  u8g2.begin();
  //u8g2.setDisplayRotation(U8G2_R2); // ROTATE 180 (Header Pins on the right)
  u8g2.setFontMode(1);  //activate transparent font mode
  u8g2.setDrawColor(2);
  u8g2.setFont(u8g2_font_7x13_t_cyrillic); // 9 pixel height

  // Setup Buttons
  left.setDebounceTime(50);
  center.setDebounceTime(50);
  right.setDebounceTime(50);

  // Setup HID-Project
  Keyboard.begin();

  // Display the logo on startup
  u8g2.clearBuffer();
  u8g2.drawXBMP(0, 0, image_width, image_height, image_bits);
  u8g2.drawStr(32, 11, "github.com/");
  u8g2.drawStr(32, 23, "Babaganoush07");
  u8g2.sendBuffer();
  delay(3000); // Is 2 seconds enough or too much?
}

void loop() {
  // ezButton Loops
  left.loop();
  center.loop();
  right.loop();

  // OLED Loop
  u8g2.clearBuffer();    // Clear the internal memory

  // ALL
  u8g2.drawFrame(2, 0, 40, 28);
  u8g2.setCursor(5, 19);
  u8g2.print(" ALL ");
  
  if(left.isPressed()){
    u8g2.drawBox(3, 1, 38, 26);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_A);
  }

  // COPY
  u8g2.drawFrame(44, 0, 40, 28);
  u8g2.setCursor(51, 19);
  u8g2.print("COPY");
  
  if(center.isPressed()){
    u8g2.drawBox(45, 1, 38, 26);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_C);
  }

  // PASTE
  u8g2.drawFrame(86, 0, 40, 28);
  u8g2.setCursor(89, 19);
  u8g2.print("PASTE");
  
  if(right.isPressed()){
    u8g2.drawBox(87, 1, 38, 26);
    Keyboard.press(KEY_LEFT_CTRL);
    //Keyboard.press(KEY_LEFT_SHIFT); // Paste Without Formatting
    Keyboard.press(KEY_V);
  }
  
  Keyboard.releaseAll();
  u8g2.sendBuffer();
}
