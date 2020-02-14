#include <stdio.h>
#include "esp_wifi.h"
#include "mother_wifi.h"

#ifdef CONFIG_WIFI_AP_SSID
    #define SSID CONFIG_WIFI_AP_SSID
#else
    #define SSID "MOTHER-API-ACCESS-POINT"
#endif

void configure_wifi_ap(void) {
    // WiFi stack configuration. For simple usage, the WIFI_INIT_CONFIG_DEFAULT
    // marco can be used
    const wifi_init_config_t wifiSettings = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifiSettings);

    // WiFi storage configuration. By default, uses both Flash and Memory.
    esp_wifi_set_storage(WIFI_STORAGE_RAM);

    // WiFi operation mode. Can be configured to be station mode, soft AP or
    // both. Defaults to soft AP.
    esp_wifi_set_mode(WIFI_MODE_AP);

    // Remaining soft AP settings
    wifi_config_t ap_config = {
        .ap = {
            .ssid = SSID,
            .channel = 0,
            .authmode = WIFI_AUTH_OPEN,
            .max_connection = 1,
            .beacon_interval = 100
        }
    };
    
    esp_wifi_set_config(WIFI_IF_AP, &ap_config);

    // Starts the access point using all previous configuration
    esp_wifi_start();
}
