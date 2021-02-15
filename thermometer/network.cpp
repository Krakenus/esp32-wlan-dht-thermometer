#include "network.hpp"

#include <WiFi.h>
#include <HTTPClient.h>

#include "settings.h"

#ifdef DEBUG
void printWifiData()
{
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}
#endif DEBUG

bool init_wifi()
{
    unsigned char attempts = 0;
    int status;

    // attempt to connect to Wifi network:
    while(true) 
    {
        #ifdef DEBUG
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(WIFI_SSID);
        #endif
        // Connect to WPA/WPA2 network:
        #if defined(WIFI_PASSWD)
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWD);
        #else
        status = Wifi.begin(WIFI_SSID);
        #endif
        delay(10000);

        if(status != WL_CONNECTED)
        {
            attempts++;
            if(attempts >= WIFI_MAX_ATTEMPTS)
            {
                #ifdef DEBUG
                Serial.println("Wifi failed to connect");
                #endif
                return false;
            }
        }
        else
        {
            break;
        }
    }
    #ifdef DEBUG
    printWifiData();
    #endif DEBUG
    return true;
}

void send_data(float temperature, float humidity)
{
  
  HTTPClient http;
  http.begin(DHT_URL);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-Device-Id", DEVICE_ID);
  int status_code = http.POST("{\"temperature\":" + String(temperature) + ", \"humidity\": " + String(humidity) + "}");
  #ifdef DEBUG
  Serial.print("HTTP response status code: ");
  Serial.println(status_code);
  #endif DEBUG
}
