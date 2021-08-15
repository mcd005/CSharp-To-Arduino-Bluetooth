#include <Arduino.h>
#include "Joint.hpp"

Joint::Joint(String name, uint16_t startAngle, uint16_t channel) :
    jointName(name),
    currentAngle(startAngle),
    targetAngle(startAngle),
    jointChannel(channel)
{
}

String Joint::setTargetAngle(int givenAngle)
{
    targetAngle = givenAngle;
    return jointName + " target angle set to " + String(targetAngle);
}
    
void Joint::incrementPosition()
{
    if (currentAngle != targetAngle)
    {
        if (currentAngle < targetAngle) ++currentAngle;
        if (currentAngle > targetAngle) --currentAngle;
        // pwm.setPWM(jointChannel, 0, calculatePulseWidth(currentAngle));
    }
}