// InputDigitalPin.h
#ifndef INPUTDIGITALPIN_H
    #define INPUTDIGITALPIN_H

    #include <Arduino.h>

    class InputDigitalPin {
        public:
          InputDigitalPin(int pin);
          bool read();

        private:
          int pin;
    };

#endif
