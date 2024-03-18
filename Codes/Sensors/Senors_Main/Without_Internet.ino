void without_internet()
{
  //Logics for Gas..........................................................................
  int gasValue = gasRead();
  if (gasValue > 90)
  {
    alarm();
    Serial.println("Gas Alarm");
  }
  else
  {
    noAlarm();
  }

  //Logics for Fire........................................................................
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
  int energyValue = readEnergy();

  //Logics for DHT11 Sensor........................................................................
  float temp = readTemp();
  float humi = readHumi();

}
