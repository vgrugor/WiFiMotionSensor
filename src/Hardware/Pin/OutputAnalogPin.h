// OutputAnalogPin.h
#ifndef OUTPUTANALOGPIN_H
    #define OUTPUTANALOGPIN_H

    #include <Arduino.h>

    class OutputAnalogPin {
        public:
            static const int MIN_PIN_LEVEL = 0;
            static const int MAX_PIN_LEVEL = 255;
            OutputAnalogPin(int pin);
            void setLevel(int level);
            void slowSetLevel(int level, int delayMs = 2000);

        private:
            
            int pin;
    };

#endif