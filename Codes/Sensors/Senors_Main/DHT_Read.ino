float humidity;
float temperature;

int readTemp()
{
  temperature = dht.readTemperature();
  return temperature;
}

float readHumi()
{
  humidity = dht.readHumidity();
  return humidity;
}
