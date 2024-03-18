String getDatee()
{
  struct tm timeinfo;
  while(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
  }
  
  char dateStringBuff[50];
  strftime(dateStringBuff, sizeof(dateStringBuff), "%D", &timeinfo);
  String dateString = String(dateStringBuff);
  return dateString; 
}
