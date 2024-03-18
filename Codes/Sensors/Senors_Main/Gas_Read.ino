int gasVal;

int gasRead()
{
  gasVal = map(analogRead(gas_Pin), 0, 4095, 0, 100);
  return gasVal;
}
