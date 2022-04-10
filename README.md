# ESP32GithubOTA

ESP32 over the air programming by ESP32

## 
* function
  * [Update Spiffs Data](https://github.com/Hsun1031/ESP32GithubOTA#Update-Spiffs-Data)
  * [Update ESP32 Firmware](https://github.com/Hsun1031/ESP32GithubOTA#Update-ESP32-Firmware)
## function

GithubUrl: `https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>`.<br>
example: `https://raw.githubusercontent.com/Hsun1031/ESP32GithubOTA/master/example/bin/firmware.bin`<br>
Github Token: `ghp_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

### GitHub Private Repositories

```c++
  // not use token.
  ESP32PrivateGithubOTA();

  // use token.
  ESP32PrivateGithubOTA(char *token);
```

### Update Spiffs Data

```c++
/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client failed. 
 */
int spiffsOTA  (const char *spiffsUrl, const char *token);

/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param isPublic Github is Public.
 * @return true  Update Susses.
 * @return false Update or Http client failed. 
 */
int spiffsOTA  (const char *spiffsUrl,   bool isPublic = 0);
```

### Update ESP32 Firmware

```c++
/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client failed.
 */
int firmwareOTA(const char *firmwareUrl, const char *token);

/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param isPublic Github is Public.
 * @return true  Update Susses.
 * @return false Update or Http client failed.
 */
int firmwareOTA(const char *firmwareUrl, bool isPublic = 0);
```
