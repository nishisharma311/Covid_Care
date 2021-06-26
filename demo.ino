#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h> 
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
int data;
const int pulse_pin = 1; 
const int temp_pin = 0;
const int LED13 = 13; 
int Threshold = 550; 

 
PulseSensorPlayground pulseSensor; 
void setup() {
 
Serial.begin(9600); // For Serial Monitor
lcd.begin(20,4);
 
// Configure the variables
pulseSensor.analogInput(pulse_pin);
pulseSensor.blinkOnPulse(LED13); 
pulseSensor.setThreshold(Threshold);
 
if (pulseSensor.begin()) {
Serial.println(" Health Monitoring System !");
lcd.setCursor(5,0);
lcd.print("COVID CARE");
 
}
}
 
void loop() {
 
int myBPM = pulseSensor.getBeatsPerMinute(); 

if (pulseSensor.sawStartOfBeat()) { 
Serial.println(" Heath is Wealth! "); 
Serial.print("BPM: "); 
Serial.println(myBPM); 
lcd.setCursor(3,1);
lcd.print("Heath is Wealth!"); 
lcd.setCursor(5,2);
lcd.print("BPM: "); 
lcd.print(myBPM);
}
lcd.setCursor(0,3);
data = analogRead(temp_pin);
float mv = (data/1024.0)*5000;
float cel = mv/10;
lcd.print("Temperature: "); 
lcd.print(cel);
delay(20); 
}