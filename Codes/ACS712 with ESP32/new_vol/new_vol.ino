#define vin 34
const float vcc = 4.92;
const float model = .100;

const float QOV = 0.5 * vcc;
float voltage;

void setup()
{
  Serial.begin(115200);
  Serial.println(".......Start......");
}

void loop()
{
  float voltage_raw = (3.3 / 4095.0) * analogRead(vin);
  voltage = (voltage_raw - QOV ) + 0.112;
  float Current  = voltage / model;

  Serial.print("Voltage: ");
  Serial.print(((-1) * (voltage)) * 100, 3);
  Serial.print("V || Current: ");
  Serial.print((-1) * (Current), 2);
  Serial.println("A");

}
