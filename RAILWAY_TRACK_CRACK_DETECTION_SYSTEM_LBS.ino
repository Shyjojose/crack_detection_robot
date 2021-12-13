
#include <LiquidCrystal.h>
#define DEBUG true
//============================================
#define echoPin A4 // Echo Pin
#define trigPin A5 // Trigger Pin


char serialData;
int count = 0;
String inputString = "";         // a string to hold incoming data
String inputString2 = "";
boolean stringComplete = false;  // whether the string is complete


int countstate = 0;

int switchstatus = 1;

char d;
char e;
//===========================================================






//====Transmission motor left=============
const int relayout1Pin = 10;//buzzer pins
const int relayout2Pin = 11;//buzzer pins
//=====================================

//====Transmission Motor Right===========
const int relayout3Pin = 12;//buzzer pins
const int relayout4Pin = 13;//buzzer pins
//========================================

const int buzzerPin = A0;//buzzer pins
int buzzerState = 0;

//==================================
const int ir1Pin = 8;
const int ir2Pin = 9;

int ir1State = 1;
int ir2State = 1;
//==================================

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


//======================================
const int switch1Pin = A1;
const int switch2Pin = A2;
const int switch3Pin = A3;
int switch1State = 1;
int switch2State = 1;
int switch3State = 1;
//======================================


int relayout1State = 0;
int relayout2State = 0;
int relayout3State = 0;
int relayout4State = 0;

//========================================

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir1Pin, INPUT_PULLUP);
  pinMode(ir2Pin, INPUT_PULLUP);

  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);

  pinMode(switch3Pin, INPUT_PULLUP);

  Serial.begin(9600);

  pinMode(relayout1Pin, OUTPUT);
  pinMode(relayout2Pin, OUTPUT);
  pinMode(relayout3Pin, OUTPUT);
  pinMode(relayout4Pin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  relayout1State = LOW;
  relayout2State = LOW;
  relayout3State = LOW;
  relayout4State = LOW;

  digitalWrite(relayout1Pin, relayout1State);
  digitalWrite(relayout2Pin, relayout2State);
  digitalWrite(relayout3Pin, relayout3State);
  digitalWrite(relayout4Pin, relayout4State);

  buzzerState = LOW;
  digitalWrite(buzzerPin, buzzerState);

  lcd.begin(16, 2);
  lcd.print("RAILWAY TRACK");
  lcd.setCursor(0, 1);
  lcd.print("CRACK DETECTION");
  delay(3000);
  //===============
  Serial.begin(9600);

  lcd.print("GSM Initializing");
  lcd.setCursor(0, 1);
  lcd.print(">>>>>>>>>>>>> ");
  delay(2000);
  Serial.println("AT");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println("AT+CMGD=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println("AT+CMGD=2");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println("AT+CSMS=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.print("AT+CSCS=");    //Sets the GSM Module in Text Mode
  Serial.print((char)34);    //Sets the GSM Module in Text Mode
  Serial.print("GSM");    //Sets the GSM Module in Text Mode
  Serial.println((char)34);    //Sets the GSM Module in Text Mode
  delay(2000);
  Serial.println("AT+CNMI=2,2,0,0,0");    //Sets the GSM Module in Text Mode
  delay(1000);
  delay(1000);
  Serial.println("AT+CSMP=17,167,0,0");    //Sets the GSM Module in Text Mode
  delay(1000);
  lcd.clear();
  lcd.print("System Ready");

  //======================
  Serial.begin(9600);

}

void loop()
{

startup:
  lcd.clear();
  lcd.print("Press Switch");
  lcd.setCursor(0, 1);
  lcd.print("to Start");
  delay(200);

  switch1State = digitalRead(switch1Pin);
  switch2State = digitalRead(switch2Pin);
  switch3State = digitalRead(switch3Pin);

  if (switch1State == LOW)
  {
    lcd.clear();
    lcd.print("Moving Forward");
    relayout1State = LOW;
    relayout2State = HIGH;
    relayout3State = LOW;
    relayout4State = HIGH;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
    delay(1000);
    relayout1State = LOW;
    relayout2State = LOW;
    relayout3State = LOW;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
  }

  if (switch2State == LOW)
  {
    lcd.clear();
    lcd.print("Moving Reverse");
    relayout1State = HIGH;
    relayout2State = LOW;
    relayout3State = HIGH;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
    delay(1000);
    relayout1State = LOW;
    relayout2State = LOW;
    relayout3State = LOW;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
  }

  if (switch3State == LOW)
  {
    lcd.clear();
    lcd.print("Moving Forward");
    relayout1State = LOW;
    relayout2State = HIGH;
    relayout3State = LOW;
    relayout4State = HIGH;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
     delay(2000);
    goto label1;
    delay(1000);
  }
  goto startup;

  //========================================
label1:


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;

   lcd.setCursor(0, 1);
  lcd.print(distance);

  
  if (distance < 10)
  {
    lcd.clear();
    lcd.print("Obstacle");
    lcd.setCursor(0, 1);
    lcd.print("Detected!!!!");
    relayout1State = LOW;
    relayout2State = LOW;
    relayout3State = LOW;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
    buzzerState = HIGH;
    digitalWrite(buzzerPin, buzzerState);
     delay(3000);
    Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    Serial.println("AT+CMGS=\"+919562342468\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.print("Obstacle Detected");// The SMS text you want to send
    delay(1000);
    Serial.println((char)26);// ASCII code of CTRL+Z
    delay(2000);
    lcd.clear();
    lcd.println("SMS Sent !!!");
    buzzerState = LOW;
    digitalWrite(buzzerPin, buzzerState);
    delay(2000);
    goto startup;
  }




  ir1State = digitalRead(ir1Pin);
  ir2State = digitalRead(ir2Pin);

  if (ir1State == HIGH)
  {
    lcd.clear();
    lcd.print("Left - Crack");
    lcd.setCursor(0, 1);
    lcd.print("Detected!!!!");
    relayout1State = LOW;
    relayout2State = LOW;
    relayout3State = LOW;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
    buzzerState = HIGH;
    digitalWrite(buzzerPin, buzzerState);
    delay(3000);
    Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    Serial.println("AT+CMGS=\"+919562342468\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.print("Crack Detected - Left.");// The SMS text you want to send
    delay(1000);
    Serial.println((char)26);// ASCII code of CTRL+Z
    delay(2000);
    lcd.clear();
    lcd.println("SMS Sent !!!");
    buzzerState = LOW;
    digitalWrite(buzzerPin, buzzerState);
    delay(3000);
    goto startup;
  }

  if (ir2State == HIGH)
  {
    lcd.clear();
    lcd.print("Right - Crack");
    lcd.setCursor(0, 1);
    lcd.print("Detected!!!!");
    relayout1State = LOW;
    relayout2State = LOW;
    relayout3State = LOW;
    relayout4State = LOW;
    digitalWrite(relayout1Pin, relayout1State);
    digitalWrite(relayout2Pin, relayout2State);
    digitalWrite(relayout3Pin, relayout3State);
    digitalWrite(relayout4Pin, relayout4State);
    buzzerState = HIGH;
    digitalWrite(buzzerPin, buzzerState);
    delay(3000);
    Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    Serial.println("AT+CMGS=\"+919562342468\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.print("Crack Detected - Right. Location: ");// The SMS text you want to send
    delay(1000);
    Serial.println((char)26);// ASCII code of CTRL+Z
    delay(2000);
    lcd.clear();
    lcd.println("SMS Sent !!!");
    buzzerState = LOW;
    digitalWrite(buzzerPin, buzzerState);
    delay(3000);
    goto startup;
  }

  goto label1;

}
