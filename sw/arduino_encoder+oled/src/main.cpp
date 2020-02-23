#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "printf.h"
#include "display.h"
#include "rotsensors.h"


void setup() {
    Serial.begin(9600);
    printf_init();
    display_init();
    rotsensors_init();
}

void loop() {
    display_print(rs_l.GetCounter(), rs_r.GetCounter());
}
