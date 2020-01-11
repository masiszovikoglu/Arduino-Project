



int temp;
int tempPin = 0;


/* Pins of ultrasonic sensor*/
int trigPin = 6; 
int echoPin = 7; 

long duration;
long distance;
int x;


int buzzer=3; 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  /* LCD adress*/

void setup(){
  randomSeed(analogRead(2));
  lcd.init();                      /* initialize the lcd */
  lcd.backlight();
  
  lcd.home();
  
  
 
 

  pinMode(buzzer,OUTPUT); 
 pinMode(2, INPUT);
 Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 

}

int backlightState = LOW;
long previousMillis = 0;
long interval = 100000;
  
void loop(){
  
  
  lcd.clear();                      /* asking user to choose a mode*/
  lcd.setCursor(0,0);
  lcd.print("Tap touch sensor");
  lcd.setCursor(0,1);
  lcd.print("to choose mod");
  delay(2000);
  lcd.clear();
  lcd.print(1);
  lcd.print(" Push ups");
  delay(1500);
  
  if (digitalRead(2)==HIGH){   /* mod 2 is selected*/
  lcd.clear();
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("21*C is best for ");
  lcd.setCursor(0,1);
  lcd.print("indoor exercises");
  delay(3000);
  
  while(1){
 
 lcd.clear();

  temp = analogRead(0);
                                       /* Reading value from temperature sensor and converting it to Celcius*/
   temp = temp *( 0.380828125);
   lcd.setCursor(5,0);
   lcd.print("Temp:");
   lcd.print(temp);
   lcd.print("*C"); 

   lcd.setCursor(0,1);
   lcd.print("Count:");
lcd.print(x);  
 
 if (digitalRead(2) == HIGH){
 Serial.println("Sensor is touched");
 digitalWrite(buzzer,HIGH); 
 delay(100);                  
 digitalWrite(buzzer,LOW);} 

digitalWrite(trigPin, LOW);    /* calculating the distance*/
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
  duration = pulseIn(echoPin, HIGH); 
  distance= duration/29.1/2;            
  
  lcd.setCursor(0,0); 
  lcd.print(distance); 
  Serial.print("distance ");  
  Serial.print(distance); 
  Serial.println(" in CM");  
  delay(20); 
  
  /* checking if person is close enough and stays for a certain duration*/  
  if (distance <8)
  delay(1000);
  if (distance<8){
  digitalWrite(buzzer,HIGH); 
  digitalWrite(8,HIGH);
  x++;
 delay(100);
 
 digitalWrite(buzzer,LOW);
 delay(100);
 digitalWrite(8,LOW);}

 
 
 delay(1000);

 

}
  }


lcd.clear();
lcd.print(2);
lcd.print(" Reaction Time");
lcd.setCursor(0,1);

delay(1500);
if (digitalRead(2)==HIGH){              /* Mode 2 is selected */
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tap the sensor");
  lcd.setCursor(0,1);
  lcd.print("after the sound ");
  delay(5000);
  lcd.clear();
  delay(2000);
  while(1){
  delay(random(200,2000));
   unsigned long time=millis();
  digitalWrite(buzzer,HIGH);
  digitalWrite(8,HIGH);
 delay(100);
 digitalWrite(buzzer,LOW);
while(1){
 if (digitalRead(2)== HIGH){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(millis()-time-100); /* duration between sound and the touch*/
  
  lcd.print(" milliseconds");
  delay(2000);
  lcd.clear();
  break;
 }
}
digitalWrite(8,LOW);
 delay(10000);
}
}
   
  
}
