int fireVal;

int fireRead()
{
  fireVal = digitalRead(fire_Pin); // 0 = Fire || 1 = No_Fire
  return fireVal;
}
