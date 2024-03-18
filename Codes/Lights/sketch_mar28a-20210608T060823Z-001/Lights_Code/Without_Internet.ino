void without_internet()
{
  state_1 = EEPROM.read(0);
  digitalWrite(Light_1, state_1);
  state_2 = EEPROM.read(1);
  digitalWrite(Light_2, state_2);
  
//conrol light_1 with the push Button.......................................................................
  int btn_val_1 = button_read(Button_1);
  if (btn_val_1 != 0)
  {
    state_1 = !digitalRead(Light_1);
    digitalWrite(Light_1, state_1);
    EEPROM.write(0, digitalRead(Light_1));
    EEPROM.commit();
    sendData = false;
  }

//conrol light_1 with the push Button.......................................................................
  int btn_val_2 = button_read(Button_2);
  if (btn_val_2 != 0)
  {
    state_2 = !digitalRead(Light_2);
    digitalWrite(Light_2, state_2);
    EEPROM.write(1, digitalRead(Light_2));
    EEPROM.commit();
    sendData = false;
  }
  
}
