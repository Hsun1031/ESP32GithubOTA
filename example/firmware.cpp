#include <Arduino.h>
#include <ESP32GithubOTA.h>

#include "SPIFFS.h"

#define LED_PIN 2

#define SSID   SSID
#define PASSWD PASSWD

#define FIRMWARE_BIN_URL FIRMWARE_BIN_URL
#define GITHUB_TOKEN     GITHUB_TOKEN

ESP32GithubOTA githubOTA;

void setup() {
    Serial.begin(115200);
    Serial.printf("\n\n");
    Serial.printf("ESP32 Start\n");

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    Serial.printf("Connect to %s...", SSID);
    WiFi.begin(SSID, PASSWD);

    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.printf("\n");
    Serial.printf("ESP32 IP: %s\n", WiFi.localIP().toString().c_str());

    Serial.printf("Start Firmware OTA\n");
    if(!githubOTA.firmwareOTA(SPIFFS_BIN_URL, GITHUB_TOKEN)) {
        Serial.printf("Error Code: %d\n", githubOTA.getErrorCode());
    }
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);

    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
