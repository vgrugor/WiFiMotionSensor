#include "App/MotionSensor/MotionSensor.h"

MotionSensor::MotionSensor(const int motionSensorPin)
    : motionSensorPin(InputDigitalPin(motionSensorPin))
{
}

bool MotionSensor::hasMotionDetected() {
    return this->motionSensorPin.read();
}
