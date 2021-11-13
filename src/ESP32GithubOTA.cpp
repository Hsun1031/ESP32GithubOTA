#include <ESP32GithubOTA.h>

ESP32GithubOTA::ESP32GithubOTA () {
    errorCode = 0;
}

bool ESP32GithubOTA::spiffsOTA  (const char *spiffsUrl, const char *token) {
    clientGithub(spiffsUrl, token, U_SPIFFS);
}

bool ESP32GithubOTA::firmwareOTA(const char *firmwareUrl, const char *token) {
    clientGithub(firmwareUrl, token, U_FLASH);
}

bool ESP32GithubOTA::clientGithub(const char *url, const char *token, int command) {
    uint16_t num = 0;
    while(*(token + num++) != 0);
    char str[num + 6] = "token ";
    char *authorization = strcat(str, token);
    
    HTTPClient http;
    http.begin(url);
    http.addHeader("Authorization", authorization);

    int httpCode = http.GET();
    if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
            WiFiClient *StreamPtr = http.getStreamPtr();
            if(runUpdate(*StreamPtr, http.getSize(), command)) {
                ESP.restart();
            }
        } else {
            errorCode = httpCode;
        }
    } else {
        errorCode = httpCode;
    }
    
    http.end();
    return false;
}

bool ESP32GithubOTA::runUpdate(Stream& data, size_t size, int command) {
    if(!Update.begin(size, command)) {
        errorCode = 1;
        return false;
    }

    if(Update.writeStream(data) != size) {
        errorCode = 2;
        return false;
    }

    if(!Update.end()) {
        errorCode = 3;
        return false;
    }

    return true;
}