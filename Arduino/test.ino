
#include "Arduino_LED_Matrix.h"
#include <stdint.h>

ArduinoLEDMatrix matrix;

const uint32_t frames[][4] =
    {
        {0xe0000000,
         0x0,
         0x0,
         66},
        {0x400e0000,
         0x0,
         0x0,
         66}};

void setup()
{
    matrix.loadSequence(frames);
    matrix.begin();
    matrix.play(true);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}