/**
 * @file ESP32GithubOTA.h
 * @author Hsun (hsun1031@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ESP32_Github_OTA
#define ESP32_Github_OTA

    #include <Arduino.h>
    #include <WiFi.h>
    #include <HTTPClient.h>
    #include <update.h>

    class ESP32GithubOTA {
        private:
            uint8_t errorCode;

        private:    
            bool runUpdate(Stream& data, size_t size, int command);
            bool clientGithub(const char *url, const char *token, int command);
        
        public:
            ESP32GithubOTA ();
            
            bool spiffsOTA  (const char *spiffsUrl, const char *token);
            bool firmwareOTA(const char *firmwareUrl, const char *token);

            /**
             * @brief Get the Error Code 
             * 
             * @return 0 -> OK
             * @return 1 -> update begin error
             * @return 2 -> update writeStream error
             * @return 3 -> update end error.
             * @return 404 -> Url error or token
             */
            uint8_t getErrorCode(){ return errorCode; };
    };

#endif