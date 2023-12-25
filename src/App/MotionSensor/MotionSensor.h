// MotionSensor.h
#ifndef MOTION_SENSOR_H
    #define MOTION_SENSOR_H

    #include <Arduino.h>
    #include "Hardware/Pin/InputDigitalPin.h"

    class MotionSensor {
        public:
            MotionSensor(const int motionSensorPin);
            bool hasMotionDetected();

        private:
            InputDigitalPin motionSensorPin;
    };

#endif