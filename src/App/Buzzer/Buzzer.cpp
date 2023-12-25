#include "App/Buzzer/Buzzer.h"

Buzzer::Buzzer(const int buzzerPin)
    : buzzerPin(OutputDigitalPin(buzzerPin))
{
}

void Buzzer::turnOn(int time) {
    this->buzzerPin.turnOff();
    delay(time);
    this->buzzerPin.turnOn();
}

void Buzzer::turnOff() {
    this->buzzerPin.turnOn();
}

void Buzzer::wifiConnection() {
    this->turnOn(100);
    delay(100);
    this->turnOn(100);
    delay(100);
    this->turnOn(100);
}

void Buzzer::wifiConnected() {
    this->turnOn(1000);
    delay(250);
    this->turnOff();
}

void Buzzer::motionDetected() {
    for (int i = 0; i < Buzzer::MOTION_SIGNAL_COUNT; i++) {
        this->turnOn(Buzzer::MOTION_SIGNAL_TIME);
        delay(Buzzer::MOTION_SIGNAL_DELAY);
    }
    delay(Buzzer::MOTION_SIGNAL_DELAY_AFTER_SIGNAL_END);
}
