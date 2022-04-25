#include <ESP32GithubOTA.h>

/**
 * @brief 
 * 
 * @param url Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param command U_FLASH or U_SPIFFS.
 * @return int 
 */
int ESP32GithubOTA::clientGithub(const char *url, int command) {
    HTTPClient http;
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    http.begin(url);

    return httpGet(&http, command);
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
    uint16_t num = 0;
    while(*(token + num++) != 0);
    char *authorization = NULL;
    authorization = (char *)malloc((6 + num) * sizeof(char));
    if(authorization == NULL) 
        return -1;
    
    *(authorization + 0) = 't';
    *(authorization + 1) = 'o';
    *(authorization + 2) = 'k';
    *(authorization + 3) = 'e';
    *(authorization + 4) = 'n';
    *(authorization + 5) = ' ';

    for(size_t i = 0; i < num; i++) {
        *(authorization + i + 6) = *(token + i);
    }

    HTTPClient http;
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    http.begin(url);
    http.addHeader("Authorization", authorization);
    
    return httpGet(&http, command);
}

int ESP32GithubOTA::httpGet(HTTPClient *http, int command) {
    int httpCode = http->GET();

    if(httpCode == HTTP_CODE_OK) 
        return httpGetStream(http, command);
    else
        return httpCode;
    
    http->end();
    return false;
}

int ESP32GithubOTA::httpGetStream(HTTPClient *http, int command) {
    WiFiClient *StreamPtr = http->getStreamPtr();
    return runUpdate(*StreamPtr, http->getSize(), command); 
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
    
    return 0;
}