#include <Arduino.h>
#include "motors.h"

#define DEBUG

extern ControlCallbacks Cc;
int cmd;


void setup() {
    Serial.begin(9600);
    Serial.write("Hello");
    motors_greeting();
};

void loop() {
    if (Serial.available() > 0) {
        // read the incoming byte:
        cmd = Serial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(cmd, DEC);
        Cc.Exec(cmd);
    }
}