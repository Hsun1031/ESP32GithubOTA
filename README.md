# ESP32GithubOTA

ESP32 over the air programming by ESP32

## 
* function
  * [Update Spiffs Data](https://github.com/Hsun1031/ESP32GithubOTA#Update-Spiffs-Data)
  * [Update ESP32 Firmware](https://github.com/Hsun1031/ESP32GithubOTA#Update-ESP32-Firmware)
  * [Get the Error Code](https://github.com/Hsun1031/ESP32GithubOTA#Get-the-Error-Code)
## function

GithubUrl: `https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>`.<br>
example: `https://raw.githubusercontent.com/Hsun1031/ESP32GithubOTA/master/example/bin/firmware.bin`<br>
Github Token: `ghp_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

### Update Spiffs Data

```c++
/**
 * @brief Update spiffs data.
 * 
 * @param spiffsUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client faild. 
 */
bool spiffsOTA  (const char *spiffsUrl, const char *token);
```

### Update ESP32 Firmware

```c++
/**
 * @brief Update ESP32 firmware.
 * 
 * @param firmwareUrl Github url https://raw.githubusercontent.com/<Your name>/<Your repo>/<Your branch>/<Your file path>/<Your file name>.
 * @param token Github Token.
 * @return true  Update Susses.
 * @return false Update or Http client faild.
 */
bool firmwareOTA(const char *firmwareUrl, const char *token);
```

### Get the Error Code

```C++
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
```