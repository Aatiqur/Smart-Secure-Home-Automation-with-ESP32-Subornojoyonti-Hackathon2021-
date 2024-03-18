/* Firebase Version--3.7.3 || ESP32 Version--1.0.1 */
#include "EEPROM.h"
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

#define WIFI_SSID "Nemo 4G"
#define WIFI_PASSWORD "unity@1234"

#define FIREBASE_HOST "new1-d83cb.firebaseio.com/"
#define FIREBASE_AUTH "LXEqGLS9TtL4d06hkkSN5Rnex6IBxnaEtxzMhIRa"

FirebaseData firebaseData;
FirebaseJson json;
void printResult(FirebaseData &data);

#define Light_1 18
#define Light_2 19

#define Button_1 17
#define Button_2 16

int state_1, state_2;

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(2);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  pinMode(Light_1, OUTPUT);
  pinMode(Light_2, OUTPUT);
  pinMode(Button_1, INPUT_PULLUP);
  pinMode(Button_2, INPUT_PULLUP);

}
void loop()
{
  while (WiFi.status() != WL_CONNECTED)
  {
    without_internet();
  }
  with_internet();
}
