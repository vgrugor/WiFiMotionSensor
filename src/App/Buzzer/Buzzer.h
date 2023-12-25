// Buzzer.h
#ifndef BUZZER_H
    #define BUZZER_H

    #include <Arduino.h>
    #include "Hardware/Pin/OutputDigitalPin.h"

    class Buzzer {
        public:
            Buzzer(const int buzzerPin);
            void turnOn(int time = 1000);
            void turnOff();
            void wifiConnection();
            void wifiConnected();
            void motionDetected();

        private:
            const int MOTION_SIGNAL_TIME = 50;
            const int MOTION_SIGNAL_COUNT = 1;
            const int MOTION_SIGNAL_DELAY = 100;
            const int MOTION_SIGNAL_DELAY_AFTER_SIGNAL_END = 2000;
            OutputDigitalPin buzzerPin;
    };

#endif
