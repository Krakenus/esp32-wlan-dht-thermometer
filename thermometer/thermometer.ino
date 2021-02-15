#include <DHT.h>

#include "settings.h"
#include "misc.hpp"
#include "network.hpp"

DHT dht(DHT_PIN, DHT22);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  #ifdef DEBUG
  Serial.begin(115200);
  Serial.print("DEVICE ID: ");
  Serial.println(DEVICE_ID);
  #endif DEBUG

  dht.begin();

  if(!init_wifi())
  {
    blink_forever();
  }
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan(temperature) || isnan(humidity))
  {
    #ifdef DEBUG
    Serial.println("DHT values reading failed");
    #endif DEBUG
    return;
  }
  #ifdef DEBUG
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  #endif DEBUG

  send_data(temperature, humidity);
  delay(LOOP_DELAY);
}
