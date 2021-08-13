#include <Arduino.h>

void setup()
{
    // initialize both serial ports:
    Serial.begin(9600);
    Serial.setTimeout(10);

    Serial1.begin(38400); // You will need to go into AT mode on the HC05 to check the baud rate. By default it's 38400
    Serial1.setTimeout(10);
}

void loop()
{
    // read from port 1, send to port 0:
    // If this is the only function in the loop, it essential just iterators over the Serial1 buffer and prints it to the console
    if (Serial1.available())
    {
        char inByte = Serial1.read(); // Read takes a single byte off the top of the buffer. Serial.available() would return 0 if called again
        Serial.write(inByte); // Writes binary data to the SerialPort. Will convert from int to ASCII char quite happily (hence prints NULL if you try to print 0)
    }

    // if (Serial1.available())
    // {
    //     String phraseFromBT = Serial1.readString(); // Reads the entire buffer into the string but will be slow if timeout is large i.e > 10 ms
    //     Serial.println(phraseFromBT);
    // }

    // read from port 0 (i.e. USB), send to port 0:
    if (Serial.available())
    {
        String inPhrase = Serial.readString();
        Serial.println(inPhrase);
    }
}