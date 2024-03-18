/*ESP32 Version--1.0.6*/
#include <WiFi.h>
#include <WiFiClientSecure.h>

#define WIFI_SSID "Nemo 4G"
#define WIFI_PASSWORD "unity@1234"

const char* host = "script.google.com";
const int httpsPort = 443;
const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String GAS_ID = "AKfycbxTL0gag2CPQoFdyklTZb0nYhUtsyXnWXIwZZkDx4ZYZMPUTz8ZqrUfgLDjEu8MojA";//Google App Script API Key

WiFiClientSecure client;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void loop()
{
}
