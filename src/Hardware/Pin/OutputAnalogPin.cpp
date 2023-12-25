#include "OutputAnalogPin.h"

OutputAnalogPin::OutputAnalogPin(int pin) : pin(pin) 
{
}

void OutputAnalogPin::setLevel(int level) {
	if (level > MAX_PIN_LEVEL) {
		level = MAX_PIN_LEVEL;
	}

	if (level < MIN_PIN_LEVEL) {
		level = MIN_PIN_LEVEL;
	}

	analogWrite(this->pin, level);
}

void OutputAnalogPin::slowSetLevel(int level, int delayMs) {
	if (level > MAX_PIN_LEVEL) {
		level = MAX_PIN_LEVEL;
	}

	if (level < MIN_PIN_LEVEL) {
		level = MIN_PIN_LEVEL;
	}

	//TODO add for(), delay, time calculation
	analogWrite(this->pin, level);
}
