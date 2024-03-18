int button_read(int btn_pin)
{
  int cl = 0;
  p:  int t = 0;
  
  if (digitalRead(btn_pin) == 0) 
  {
    while (digitalRead(btn_pin) == 0) 
    {
      delay(1);
      t++;
    }
    
    if (t > 15)
    {
      t = 0;
      cl++;
      while (digitalRead(btn_pin) == 1)
      {
        delay(1);
        t++;
        if (t > 1000) return cl;
      }
      goto p;
    }
  }
  return cl;
}
