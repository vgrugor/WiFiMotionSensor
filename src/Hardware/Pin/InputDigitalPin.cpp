#include "Hardware/Pin/InputDigitalPin.h"

InputDigitalPin::InputDigitalPin(int pin) : pin(pin)
{
}

bool InputDigitalPin::read() {
    return digitalRead(this->pin);
}
