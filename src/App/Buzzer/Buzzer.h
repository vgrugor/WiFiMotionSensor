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
            OutputDigitalPin buzzerPin;
    };

#endif
