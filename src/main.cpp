#include <Arduino.h>

#include "App/Facades/WiFi/WiFiConnectionFacade.h"
#include "env.h"
#include "App/Buzzer/Buzzer.h"
#include "App/MotionSensor/MotionSensor.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

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
		WiFiClient client;
		HTTPClient http;

		String serverPath = "http://192.168.1.200:80/sensor/motion?sensor=1";
		
		http.begin(client, serverPath.c_str());

		int httpResponseCode = http.GET();
		
		if (httpResponseCode > 0) {
			Serial.print("HTTP Response code: ");
			Serial.println(httpResponseCode);
			String payload = http.getString();
			Serial.println(payload);
		}
		else {
			Serial.print("Error code: ");
			Serial.println(httpResponseCode);
		}

		http.end();


		BuzzerSignalizator.motionDetected();
	}
}
