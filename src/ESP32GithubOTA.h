#ifndef ESP32_Github_OTA
#define ESP32_Github_OTA

    #include <Arduino.h>
    #include <WiFi.h>
    #include <HTTPClient.h>
    #include <update.h>

    class ESP32GithubOTA {
    private:
        uint8_t errorCode;
        bool runUpdate(Stream& data, size_t size, int command);
        bool clientGithub(const char *url, const char *token, int command);
       
    public:
        ESP32GithubOTA ();

        bool spiffsOTA  (const char *spiffsUrl, const char *token);
        bool firmwareOTA(const char *firmwareUrl, const char *token);
        uint8_t getErrorCode(){ return errorCode; };
    };

#endif