#include <Arduino.h>

#include "App/Facades/WiFi/WiFiConnectionFacade.h"
#include "env.h"
#include "App/Buzzer/Buzzer.h"
#include "App/MotionSensor/MotionSensor.h"

WiFiConnectionFacade WiFiConnection {WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET};
Buzzer BuzzerSignalizator {BUZZER_PIN};
MotionSensor Sensor {MOTION_SENSOR_PIN};

void setup() {
	Serial.begin(115200);

	pinMode(BUZZER_PIN, OUTPUT);
	pinMode(MOTION_SENSOR_PIN, INPUT);

	BuzzerSignalizator.turnOff();

	BuzzerSignalizator.wifiConnection();
	WiFiConnection.initAndConnect();
	BuzzerSignalizator.wifiConnected();
}

void loop() {
	if(!WiFiConnection.isConnected()) {
		BuzzerSignalizator.wifiConnection();
		WiFiConnection.reconnect();
		BuzzerSignalizator.wifiConnected();
	}

	if (Sensor.hasMotionDetected()) {
		BuzzerSignalizator.motionDetected();
	}
}
