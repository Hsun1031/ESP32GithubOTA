#include <Arduino.h>
#include <ESP32GithubOTA.h>

#include "SPIFFS.h"

#define SSID   SSID
#define PASSWD PASSWD

#define SPIFFS_BIN_URL SPIFFS_BIN_URL
#define GITHUB_TOKEN   GITHUB_TOKEN

ESP32GithubOTA githubOTA;

void openFile();

void setup() {
    Serial.begin(115200);
    Serial.printf("\n\n");
    Serial.printf("ESP32 Start\n");

    Serial.printf("Connect to %s...", SSID);
    WiFi.begin(SSID, PASSWD);

    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.printf("\n");
    Serial.printf("ESP32 IP: %s\n", WiFi.localIP().toString().c_str());

    openFile();

    Serial.printf("Start SPIFFS OTA\n");
    if(!githubOTA.spiffsOTA(SPIFFS_BIN_URL, GITHUB_TOKEN)) {
        Serial.printf("Error Code: %d\n", githubOTA.getErrorCode());
    }
}

void loop() {

}

void openFile() {
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        for(;;);
    }

    File file = SPIFFS.open("/data.txt");
    if(file){
        Serial.printf("File Content:\n");
        while(file.available()){
            Serial.write(file.read());
        }
        Serial.printf("\n");
    }else{
        Serial.printf("Error\n");
    }
    file.close();
}