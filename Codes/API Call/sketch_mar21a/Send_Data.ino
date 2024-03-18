void sendData(String Name)
{
  client.setInsecure();
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort))
  {
    Serial.println("connection failed");
    return;
  }
  if (client.verify(fingerprint, host))
  {
    Serial.println("certificate matches");
  }
  else
  {
    Serial.println("certificate doesn't match");
  }

  String url = "https://script.google.com/macros/s/" + GAS_ID + "/exec?tag=" + Name;

  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("request sent");
  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    if (line == "\r")
    {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\""))
  {
    Serial.println("ESP32 CI successfull!");
  } else
  {
    Serial.println("ESP32 CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}
