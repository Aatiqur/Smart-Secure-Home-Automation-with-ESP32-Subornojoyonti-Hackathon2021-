bool sendData;

void with_internet()
{
  state_1 = EEPROM.read(0);
  state_2 = EEPROM.read(1);
  digitalWrite(Light_1, state_1);
  digitalWrite(Light_2, state_2);

  if (sendData == false)
  {
    if (state_1 == 0)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light1", "6543211");
      sendData = true;
    }
    else if (state_1 == 1)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light1", "6543212");
      sendData = true;
    }
    if (state_2 == 0)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light2", "6543213");
      sendData = true;
    }
    else if (state_2 == 1)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light2", "6543214");
      sendData = true;
    }
  }



  //get the light_1 state and control the light_1 according to that state.................................
  if (Firebase.getString(firebaseData, "/Users/654321/Light1"))
  {
    if (firebaseData.stringData() == "6543211")
    {
      digitalWrite(Light_1, 0);//Turn the relay on
      EEPROM.write(0, digitalRead(Light_1));
      EEPROM.commit();
    }
    else if (firebaseData.stringData() == "6543212")
    {
      digitalWrite(Light_1, 1);//Turn the relay off
      EEPROM.write(0, digitalRead(Light_1));
      EEPROM.commit();
    }
  }

  //get the light_1 state and control the light_1 according to that state.................................
  if (Firebase.getString(firebaseData, "/Users/654321/Light2"))
  {
    if (firebaseData.stringData() == "6543213")
    {
      digitalWrite(Light_2, 0);//Turn the relay on
      EEPROM.write(1, digitalRead(Light_2));
      EEPROM.commit();
    }
    else if (firebaseData.stringData() == "6543214")
    {
      digitalWrite(Light_2, 1);//Turn the relay off
      EEPROM.write(1, digitalRead(Light_2));
      EEPROM.commit();
    }
  }

  //conrol light_1 with the push Button.......................................................................
  int btn_val_1 = button_read(Button_1);
  if (btn_val_1 != 0)
  {
    state_1 = !digitalRead(Light_1);
    digitalWrite(Light_1, state_1);
    EEPROM.write(0, digitalRead(Light_1));
    EEPROM.commit();
    if (state_1 == 0)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light1", "6543211");
      sendData = true;
    }
    else if (state_1 == 1)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light1", "6543212");
      sendData = true;
    }
  }

  //conrol light_2 with the push Button.......................................................................
  int btn_val_2 = button_read(Button_2);
  if (btn_val_2 != 0)
  {
    state_2 = !digitalRead(Light_2);
    digitalWrite(Light_2, state_2);
    EEPROM.write(1, digitalRead(Light_2));
    EEPROM.commit();
    if (state_2 == 0)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light2", "6543213");
      sendData = true;
    }
    else if (state_2 == 1)
    {
      Firebase.setString(firebaseData, "/Users/654321/Light2", "6543214");
      sendData = true;
    }
  }


  //Send the light_1 states............................................................................

  //Send the light_2 states............................................................................

}
