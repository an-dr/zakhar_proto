#include "RotSensor.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

/**** Settings ****/
#define OLED_RESET 4
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
Adafruit_SSD1306 display(-1);

int left_encoder_pin = 2;  // pulse output from the module
int right_encoder_pin = 3; // pulse output from the module

RotSensor rs_l(left_encoder_pin, "Left", millis);
RotSensor rs_r(right_encoder_pin, "Right", millis);

/**** For printf ****/
int getChar(FILE *fp) {
    while (!(Serial.available()))
        ;
    return (Serial.read());
}

int putChar(char c, FILE *fp) {
    if (c == '\n') {
        putChar((char)'\r', fp);
    }
    Serial.write(c);
    return 0;
}
/* For printf <- */




void setup() {
    Serial.begin(9600);
    fdevopen(putChar, getChar);
    // encoders
    attachInterrupt(digitalPinToInterrupt(rs_l.GetPin()), rs_l.GetIntrHandler(), FALLING);
    attachInterrupt(digitalPinToInterrupt(rs_r.GetPin()), rs_r.GetIntrHandler(), FALLING);
    // display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Hello!");
    display.display();
    delay(500);
    display.clearDisplay();
}

void loop() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Left: ");
    display.println(rs_l.GetCounter());
    display.print("Right: ");
    display.println(rs_r.GetCounter());
    display.display();
}
