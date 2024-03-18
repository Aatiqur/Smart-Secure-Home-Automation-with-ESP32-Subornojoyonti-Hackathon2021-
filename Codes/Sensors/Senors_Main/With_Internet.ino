void with_internet()
{
  //Logics for Gas Sensor..........................................................................
  int gasValue = gasRead();
  Firebase.setInt(firebaseData, "/Users/654321/Gas", gasValue);
  if (gasValue > 90)
  {
    alarm();
    Serial.println("Gas Alarm");
  }
  else
  {
    noAlarm();
  }

  //Logics for Fire Sensor........................................................................
  int fireValue = fireRead();
  Firebase.setInt(firebaseData, "/Users/654321/Fire", fireValue);
  if (fireValue == 0)
  {
    alarm();
    Serial.println("Fire Alarm");
  }
  else
  {
    noAlarm();
  }

  //Logics for Energy Sensor........................................................................
  float energyValue = readEnergy();
  Firebase.setFloat(firebaseData, "/Users/654321/Unit", energyValue);

  //Logics for DHT11 Sensor........................................................................
  float temp = readTemp();
  Firebase.setFloat(firebaseData, "/Users/654321/Temperature", temp);

  float humi = readHumi();
  Firebase.setFloat(firebaseData, "/Users/654321/Humidity", humi);

}
