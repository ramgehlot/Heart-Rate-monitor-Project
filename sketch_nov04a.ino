#include<LiquidCrystal.h>
long measurementStartTime=0;
float beats=0;
byte sensorPin=6;
int currentSensorValue;
float bpm;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  pinMode(5,INPUT);
  digitalWrite(5,HIGH);
}
void loop()
{
  if(digitalRead(5)==LOW)
  {
    Serial.print("started");
    digitalWrite(5,HIGH);
    beats=0;
    measurementStartTime=millis();
    
    while((millis()-measurementStartTime)<=25000)
    {
      currentSensorValue=digitalRead(6);
      if(currentSensorValue==HIGH)
      {
        beats++;
        delay(250);
      }
    }
    Serial.print("Your BPM is ");
    bpm=(beats*60000.0)/25000.0;
    Serial.println(bpm);
  }
}
