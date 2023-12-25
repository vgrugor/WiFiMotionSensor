#include "App/Facades/HttpClient/HttpClient.h"

HttpClient::HttpClient(String domain, String port)
    : wifiClient(WiFiClient {}),
    httpClient(HTTPClient {}),
    domainPort(domain + ":" + port)
{
}

int HttpClient::getRequest(String uri)
{
    String url = this->domainPort + uri;
    this->httpClient.begin(this->wifiClient, url.c_str());

    return this->httpClient.GET();
}
