#include <Adafruit_ADS1X15.h>

Adafruit_ADS1015 ads;

int channelValue = 0;
int sensorValue = 0;
int humidityValue = 0;

int medidaSeco = 858;
int medidaMojado= 415;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  ads.setGain(GAIN_TWOTHIRDS);  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = ads.readADC_SingleEnded(channelValue);
  humidityValue = map(sensorValue, medidaSeco, medidaMojado, 0, 100);

  Serial.println();
  Serial.print("Humedad: ");
  Serial.print(humidityValue, DEC);
  Serial.println();
  Serial.print(sensorValue);
  delay(1000);
}
