#include <ESP32GithubOTA.h>

/**
 * @brief Construct a new ESP32PrivateGithubOTA::ESP32PrivateGithubOTA object
 * 
 */
ESP32PrivateGithubOTA::ESP32PrivateGithubOTA() {

}

/**
 * @brief Construct a new ESP32PrivateGithubOTA::ESP32PrivateGithubOTA object
 * 
 * @param token Github Token.
 */
ESP32PrivateGithubOTA::ESP32PrivateGithubOTA(char *token) {
    _token = token;
}

/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param isPublic Github is Public.
 * @return true  Update Susses.
 * @return false Update or Http client failed. 
 */
int ESP32PrivateGithubOTA::spiffsOTA(const char *spiffsUrl, bool isPublic) {
    if(_token == NULL || isPublic) 
        return clientGithub(spiffsUrl, U_SPIFFS);
    return clientGithub(spiffsUrl, _token, U_SPIFFS);
}

/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client failed. 
 */
int ESP32PrivateGithubOTA::spiffsOTA(const char *spiffsUrl, const char *token) {
    return clientGithub(spiffsUrl, token, U_SPIFFS);
}

/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client failed.
 */
int ESP32PrivateGithubOTA::firmwareOTA(const char *firmwareUrl, const char *token) {
    return clientGithub(firmwareUrl, token, U_FLASH);
}

/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param isPublic Github is Public.
 * @return true  Update Susses.
 * @return false Update or Http client failed.
 */
int ESP32PrivateGithubOTA::firmwareOTA(const char *firmwareUrl, bool isPublic) {
    if(_token == NULL || isPublic) 
        return clientGithub(firmwareUrl, U_FLASH);
    return clientGithub(firmwareUrl, _token, U_FLASH);
}
