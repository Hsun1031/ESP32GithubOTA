/**
 * @file ESP32GithubOTA.h
 * @author Hsun (hsun1031@outlook.com)
 * @brief 
 * @version 2.0
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __ESP32_Github_OTA__
#define __ESP32_Github_OTA__

    #include <Arduino.h>
    #include <WiFi.h>
    #include <HTTPClient.h>
    #include <Update.h>

    class ESP32GithubOTA {
        public:    
            int runUpdate   (Stream& data, size_t size, int command);
            int clientGithub(const char *url, int command);
            int clientGithub(const char *url, const char *token, int command);
    };

    class ESP32PublicGithubOTA:ESP32GithubOTA {
        public:
            ESP32PublicGithubOTA();
            
            int spiffsOTA  (const char *spiffsUrl);
            int firmwareOTA(const char *firmwareUrl);
    };

    class ESP32PrivateGithubOTA:ESP32GithubOTA {
        private:
            char *_token = NULL;

        public:
            ESP32PrivateGithubOTA();
            ESP32PrivateGithubOTA(char *token);
            
            int spiffsOTA  (const char *spiffsUrl,   bool isPublic = 0);
            int spiffsOTA  (const char *spiffsUrl,   const char *token);
            int firmwareOTA(const char *firmwareUrl, bool isPublic = 0);
            int firmwareOTA(const char *firmwareUrl, const char *token);
    };

#endif
