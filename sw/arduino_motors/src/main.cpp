#include "ControlCallbacks.h"
#include "hw_motors.h"
#include <Arduino.h>

#define PINR1 9
#define PINR2 10
#define PINL1 11
#define PINL2 12
#define DEBUG
#define SIZE_ARR(x) (sizeof(x) / sizeof(x[0]))

Motors_dc2platform wheels(PINR1, PINR2, PINL1, PINL2);

void test(void) {
    wheels.MoveBackward();
    delay(300);
    // //     wheels.MoveRight();
    // // delay(400);
    // wheels.MoveBackward();
    // delay(2000);
    // wheels.Stop();
    // delay(300);

    wheels.MoveForward();
    delay(300);
    wheels.Stop();
}
int read_val;

void W(void) {
    wheels.MoveForward();
    delay(25);
    wheels.Stop();
}
void S(void) {
    wheels.MoveBackward();
    delay(25);
    wheels.Stop();
}
void A(void) {
    wheels.MoveLeft();
    delay(25);
    wheels.Stop();
}
void D(void) {
    wheels.MoveRight();
    delay(25);
    wheels.Stop();
}
void Stop(void) {
    wheels.Stop();
}

Connection_t connection[5] = {
    {.cmd_code = 119, .func = W},
    {.cmd_code = 115, .func = S},
    {.cmd_code = 97, .func = A},
    {.cmd_code = 100, .func = D},
    {.cmd_code = 32, .func = Stop},
};
ControlCallbacks Cc(connection, SIZE_ARR(connection));

void setup() {
    test();
    Serial.begin(9600);
    Serial.write("Hello");
};

void loop() {
    // read_val = Serial.read();
    // if (read_val) {
    //     Serial.write(read_val);
    // }

    // send data only when you receive data:
    if (Serial.available() > 0) {
        // read the incoming byte:
        read_val = Serial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(read_val, DEC);
        Cc.Exec(read_val);
    }
}