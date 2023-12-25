// OutputDigitalPin.h
#ifndef OUTPUTDIGITALPIN_H
    #define OUTPUTDIGITALPIN_H

    #include <Arduino.h>

    class OutputDigitalPin {
        public:
          OutputDigitalPin(int pin);
          void turnOn();
          void turnOff();
          void toggle();
          void blink(int count, int delayMs = 500);

        private:
          int pin;
    };

#endif
