String getTimee()
{
  struct tm timeinfo;
  while(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
  }
  
  char timeStringBuff[50];
  strftime(timeStringBuff, sizeof(timeStringBuff), "%r", &timeinfo);
  String timeString = String(timeStringBuff);
  return timeString;
}
