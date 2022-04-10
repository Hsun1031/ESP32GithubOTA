#include <ESP32GithubOTA.h>

/**
 * @brief Construct a new ESP32PublicGithubOTA::ESP32PublicGithubOTA object
 * 
 */
ESP32PublicGithubOTA::ESP32PublicGithubOTA() {

}

/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @return true  Update Susses.
 * @return false Update or Http client failed. 
 */
int ESP32PublicGithubOTA::spiffsOTA(const char *spiffsUrl) {
    return clientGithub(spiffsUrl, U_SPIFFS);
}

/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @return true  Update Susses.
 * @return false Update or Http client failed.
 */
int ESP32PublicGithubOTA::firmwareOTA(const char *firmwareUrl) {
    return clientGithub(firmwareUrl, U_FLASH);
}
