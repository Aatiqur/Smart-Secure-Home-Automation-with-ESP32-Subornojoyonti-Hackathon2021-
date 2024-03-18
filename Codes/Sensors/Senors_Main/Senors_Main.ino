/* Firebase Version--3.7.3 || ESP32 Version--1.0.1 */
#include "DHT.h"
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

//Set the wifi creadentials.........................................
#define WIFI_SSID "Nemo 4G"
#define WIFI_PASSWORD "unity@1234"

//Set the firebase creadentials.....................................
#define FIREBASE_HOST "new1-d83cb.firebaseio.com/"
#define FIREBASE_AUTH "LXEqGLS9TtL4d06hkkSN5Rnex6IBxnaEtxzMhIRa"
FirebaseData firebaseData;
FirebaseJson json;
void printResult(FirebaseData &data);

//Defines the Sensors pin numbers..................................
#define gas_Pin 32
#define energy_Pin 34
#define fire_Pin 23
#define dht_Pin 14

#define alarm_Pin 13 //Attach a buzzer with pin 13

#define DHTTYPE DHT11 //Define the DHT sensors model no.
DHT dht(dht_Pin, DHTTYPE); //Declare a object for DHT11 Sensor

//Defines necessary variables for reading energy....................
const float vcc = 4.81;
const float model = .100;
const float QOV = 0.5 * vcc;
float voltage;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //Connecting with the provided wifi network
  dht.begin(); //begin the work of DHT11 sensor

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //Connecting with Firebase Realtime Database
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  pinMode(gas_Pin, INPUT);
  pinMode(fire_Pin, INPUT);
  pinMode(dht_Pin, INPUT);
  pinMode(energy_Pin, INPUT);
  pinMode(alarm_Pin, OUTPUT);
  digitalWrite(alarm_Pin, 0);
}

void loop()
{
  while (WiFi.status() != WL_CONNECTED)
  {
    without_internet();
  }
  with_internet();
}
