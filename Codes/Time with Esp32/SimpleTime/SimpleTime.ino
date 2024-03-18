#include <WiFi.h>
#include "time.h"
#include <FirebaseESP32.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

const char* ssid       = "Nemo 4G";
const char* password   = "unity@1234";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 21600;
const int   daylightOffset_sec = 0;

#define FIREBASE_HOST "new1-d83cb.firebaseio.com/"
#define FIREBASE_AUTH "LXEqGLS9TtL4d06hkkSN5Rnex6IBxnaEtxzMhIRa"

FirebaseData firebaseData;
FirebaseJson json;
void printResult(FirebaseData &data);


void setup()
{
  Serial.begin(115200);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

}

void loop()
{
     sendData("Atiqur Rahman");
     
}

//  delay(1000);
//
//  Serial.println(getTimee());
//  String t = getTimee();
//  if(Firebase.setString(firebaseData, "/Users/654321/Time", t))
//  {
//    Serial.println("PASSED");
//        Serial.println("PATH: " + firebaseData.dataPath());
//        Serial.println("TYPE: " + firebaseData.dataType());
//        Serial.println("CURRENT ETag: " + firebaseData.ETag());
//        Serial.print("VALUE: ");
//        printResult(firebaseData);
//        Serial.println("------------------------------------");
//        Serial.println();
//  }
//     else
//    {
//        Serial.println("FAILED");
//        Serial.println("REASON: " + firebaseData.errorReason());
//        Serial.println("------------------------------------");
//        Serial.println();
//    }
//  Serial.println(getDatee());
