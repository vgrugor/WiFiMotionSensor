// WiFiConnectionFacade.h
#ifndef WIFICONNECTIONFACADE_H
    #define WIFICONNECTIONFACADE_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>

    class WiFiConnectionFacade {
        public:
            WiFiConnectionFacade(const char* ssid, const char* password, const char* ip, const char* gateway, const char* subnet);
            void initAndConnect();
            bool isConnected();
            void reconnect();

        private:
            const char* ssid;
            const char* password;
            const char* ip;
            const char* gateway;
            const char* subnet;
            ESP8266WiFiClass wifi;
            void setMode();
            void setStaticIpAddress();
            void begin();
            void connect();
            void setAutoreconnect();
    };

#endif
