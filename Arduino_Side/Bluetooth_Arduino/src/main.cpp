#include <Arduino.h>

bool isValidJoint(char inputJointChar)
{
    return (inputJointChar == 'W' ||
            inputJointChar == 'S' ||
            inputJointChar == 'E' ||
            inputJointChar == 'P' ||
            inputJointChar == 'R' ||
            inputJointChar == 'C');
}

void parseCoordsFromSerial()
{
    char serialInput[4];
    Serial1.readBytes(serialInput, 4);
    if (!isValidJoint(serialInput[0]))
    {
        Serial.println("Invalid joint");
        return;
    }
    Serial.println("Valid joint");
}

void setup()
{
    Serial.begin(9600);
    Serial.setTimeout(10);

    Serial1.begin(9600);
    Serial1.setTimeout(10);
}

void loop()
{
    if (Serial1.available())
    {
        parseCoordsFromSerial();
    }
}