#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);// LCD Pins D4-D8
const int sensorPin = A1;       // analog input from MQ-3 sensor
const int indicatorLedPin = 13; // Pin output for green LED
const int buttonPin = 12;        // input from micro switch
void setup() 
{
  lcd.begin(16, 2); // LCD size; 16 symbols per row; 2 rows
  pinMode(indicatorLedPin, OUTPUT); // Pin 13 output
   pinMode(buttonPin, INPUT); // Pin 12 input
}
void loop() 
{
  lcd.print("ALCOHOL TESTER"); //turn on inscription
  delay(3000);  //time for waiting 3000 = 3sec
  lcd.clear(); //clear the LCD
  lcd.print("Ready fot test !!!!");//inscription
  delay(3000);//time for waiting
  lcd.clear();
  lcd.setCursor(0, 0); //1st row of the LCD
  lcd.print("Blow in the test");//inscription
  lcd.setCursor(0, 1); //2nd row of the LCD
  lcd.print("device please !");//inscription
  delay(3000);//time for waiting
  int sensorValue = 0; 
  while (digitalRead(buttonPin) == LOW) {
  int sensorValue = analogRead(sensorPin); //reading sensor value
  lcd.clear(); 
  lcd.print("Run test..."); // inscription
  delay(1000);
  lcd.clear(); // clear the LCD
  lcd.print("Alcohol is ..."); // inscription
  lcd.setCursor(0, 1); // 2nd row of the LCD
  lcd.print(sensorValue); // sensor value
  delay(1000);
  lcd.clear();
  if (sensorValue<428) // if sensor value is below 428 ADC
  lcd.print("You are sober."); //inscription
  delay(1000);
  lcd.clear();
  if (sensorValue>=429 && sensorValue<646) // sensor value between 429 and 646 ADC
  lcd.print("You had a drink!"); //inscription
  delay(1000);
  lcd.clear();
  if (sensorValue>646) // sensor value above 646 ADC
  lcd.print("You are drunk!!!"); //inscription
  delay(1000);
  lcd.clear();
  

if (sensorValue < 646)   // compare the sensor value with this one
  { // if sensor value is less than 646 ADC
    // Arduino allow start of the engine
 lcd.clear(); 
  lcd.print("You have 10 sec"); //inscription
  delay(1000); 
  digitalWrite(indicatorLedPin, HIGH);  // pin 13 becomes 5V and sent voltage to the green LED.
  lcd.clear();
  lcd.print("Start 10 !!!!"); //time for starting the engine
  delay(1000);
  lcd.clear();
  lcd.print("Start 9 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 8 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 7 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 6 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 5 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 4 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 3 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 2 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 1 !!!!"); 
  delay(1000);
  lcd.clear();
  lcd.print("Start 0 !!!!"); 
  digitalWrite(indicatorLedPin, LOW); // pin 13 becomes 0 and stop the voltage to the green LED 
  }
}
  lcd.clear();
  lcd.print("Test failed..."); // inscription for test failed
  delay(1000);
  lcd.clear();
}
