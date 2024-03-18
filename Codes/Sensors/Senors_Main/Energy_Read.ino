float energy;
float unit;

float readEnergy()
{
  float voltage_raw = (3.3 / 4095.0) * analogRead(energy_Pin);
  voltage = (voltage_raw - QOV ) + 0.112;
  float Current  = voltage / model;
  energy = ((12) * ((-1) * (Current)));
  Serial.print("Voltage: ");
  Serial.print((-1) * (Current), 2);
  Serial.println("A");
  unit = energy/10;
  return unit;
}
