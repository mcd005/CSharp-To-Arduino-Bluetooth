#include <Arduino.h>

int state = 0;

void setup() {
  Serial1.begin(38400); // Default communication rate of the Bluetooth module
}

void loop()
{
    if (Serial.available() > 0)
    {                          // Checks whether data is comming from the serial port
        state = Serial.read(); // Reads the data from the serial port
        Seri
    }
    if (state == '0')
    {
        Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
        state = 0;
    }
    else if (state == '1')
    {
        Serial.println("LED: ON");
        state = 0;
    }
}