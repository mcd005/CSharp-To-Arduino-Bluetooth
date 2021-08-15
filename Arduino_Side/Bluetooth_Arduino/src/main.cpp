#include <Arduino.h>
#include "Joint.hpp"

Joint waist("waist", 0, 1);
Joint shoulder("shoulder", 0, 2);
Joint elbow("elbow", 0, 3);
Joint pitch("pitch", 0, 4);
Joint roll("roll", 0, 5);
Joint claw("claw", 0, 6);

void setup()
{
    // Serial is for the serial monitor
    Serial.begin(9600);
    Serial.setTimeout(10);

    // Serial1 is for the Bluetooth module
    Serial1.begin(9600);
    Serial1.setTimeout(10);
}

void loop()
{
    if (Serial1.available())
    {
        // Expecting a comma seperated list of coords: W10,S50,E120 etc
        String inputSerial = Serial1.readStringUntil(',');
        char jointID = inputSerial[0];
        int givenAngle = inputSerial.substring(1).toInt();
        if (jointID == 'W') Serial.println(waist.setTargetAngle(givenAngle));
        else if (jointID == 'S') Serial.println(shoulder.setTargetAngle(givenAngle));
        else if (jointID == 'E') Serial.println(elbow.setTargetAngle(givenAngle));
        else if (jointID == 'P') Serial.println(pitch.setTargetAngle(givenAngle));
        else if (jointID == 'R') Serial.println(roll.setTargetAngle(givenAngle));
        else if (jointID == 'C') Serial.println(claw.setTargetAngle(givenAngle));
        else Serial.println("Invalid joint");
    }
    waist.incrementPosition();
    shoulder.incrementPosition();
    elbow.incrementPosition();
    pitch.incrementPosition();
    roll.incrementPosition();
    claw.incrementPosition();
}
