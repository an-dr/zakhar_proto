#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

enum NOKIA_LCD_PINS {
    RST = 0x1,
    CE,
    DC,
    Din,
    Clk,
    Vcc,
    BL,
    Gnd
};

#define NOKIA_LCD_RST 12
#define NOKIA_LCD_CE 14
#define NOKIA_LCD_DC 27
#define NOKIA_LCD_Din 26
#define NOKIA_LCD_Clk 25

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

*/
U8G2_PCD8544_84X48_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/NOKIA_LCD_Clk, /* data=*/NOKIA_LCD_Din, /* cs=*/NOKIA_LCD_CE, /* dc=*/NOKIA_LCD_DC, /* reset=*/NOKIA_LCD_RST); // Nokia 5110 Display

// End of constructor list

void setup(void) {
    u8g2.begin();
}

void loop(void) {
    u8g2.setDisplayRotation(U8G2_R2);
    u8g2.clearBuffer();                   // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
    u8g2.drawStr(0, 10, "Privet Sveta!"); // write something to the internal memory
    u8g2.drawStr(0, 25, "I LOVE YOU");    // write something to the internal memory
    u8g2.drawStr(0, 40, "Andrei");        // write something to the internal memory
    u8g2.sendBuffer();                    // transfer internal memory to the display
    delay(1000);
}