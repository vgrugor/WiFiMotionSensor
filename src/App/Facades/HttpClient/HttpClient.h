// HttpClient.h
#ifndef HTTPCLIENT_H
    #define HTTPCLIENT_H

    #include <ESP8266HTTPClient.h>
    #include <WiFiClient.h>

    class HttpClient
    {
        public:
            HttpClient(String domain, String port);
            int getRequest(String uri);

        private:
            WiFiClient wifiClient;
            HTTPClient httpClient;
            String domainPort;
    };

#endif
