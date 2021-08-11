#include <Arduino.h>

void setup()
{
    // initialize both serial ports:
    Serial.begin(9600);
    Serial1.begin(9600); // I was getting garbage with a baud rate of 38400, even though that is what is suggested for the HC05
}

void loop()
{
    // read from port 1, send to port 0:
    if (Serial1.available())
    {
        char inByte = Serial1.read(); // Read takes a single byte off the top of the buffer. Serial.available() would return 0 if called again
        Serial.write(inByte); // Writes binary data to the SerialPort. Will convert from int to ASCII char quite happily (hence prints NULL if you try to print 0)
    }
}