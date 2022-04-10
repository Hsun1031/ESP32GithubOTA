#include <ESP32GithubOTA.h>

/**
 * @brief 
 * 
 * @param url Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param command U_FLASH or U_SPIFFS.
 * @return int 
 */
int ESP32GithubOTA::clientGithub(const char *url, int command) {
    Serial.printf("no token\n");
    HTTPClient http;
    http.begin(url);

    int httpCode = http.GET();
    if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
            WiFiClient *StreamPtr = http.getStreamPtr();
            if(runUpdate(*StreamPtr, http.getSize(), command))
                ESP.restart();
        } else {
            return httpCode;
        }
    } else {
        return httpCode;
    }
    
    http.end();
    return 0;
}

/**
 * @brief 
 * 
 * @param url Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @param command U_FLASH or U_SPIFFS.
 * @return int 
 */
int ESP32GithubOTA::clientGithub(const char *url, const char *token, int command) {
    Serial.printf("token\n");
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
            if(runUpdate(*StreamPtr, http.getSize(), command)) 
                ESP.restart();
        } else {
            return httpCode;
        }
    } else {
        return httpCode;
    }
    
    http.end();
    return 0;
}

/**
 * @brief 
 * 
 * @param data WiFiClient *
 * @param size http.getSize()
 * @param command U_FLASH or U_SPIFFS.
 * @return int 
 */
int ESP32GithubOTA::runUpdate(Stream& data, size_t size, int command) {
    if(!Update.begin(size, command))
        return 1;

    if(Update.writeStream(data) != size)
        return 2;

    if(!Update.end())
        return 3;
    
    return true;
}