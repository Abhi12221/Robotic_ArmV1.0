#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>
Adafruit_PWMServoDriver test = Adafruit_PWMServoDriver();
SoftwareSerial blue (2, 3);
#define xaxis A0
#define y1axis A1
#define y2axis A2
#define zaxis A3
#define gaxis A6
int x = 90;
int y1 = 90;
int y2 = 90;
int z = 90;
int g = 90;
int xraw = 375;
int y1raw = 375;
int y2raw = 375;
int zraw = 375;
int graw = 375;
int xmap = 90;
int y1map = 90;
int y2map = 90;
int zmap = 90;
int gmap = 90;
int xcount = 375;
int y1count = 375;
int y2count = 375;
int zcount = 375;
int gcount = 375;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blue.begin(9600);
  test.begin();
  test.setPWMFreq(60);
  pinMode(xaxis, INPUT);
  pinMode(y1axis, INPUT);
  pinMode(y2axis, INPUT);
  pinMode(zaxis, INPUT);
  pinMode(gaxis, INPUT);
  pinMode(4, INPUT_PULLUP);
  resetmotor();
  delay(500);
}
void resetmotor()
{
  test.setPWM(0, 0, 375);
  test.setPWM(1, 0, 375);
  test.setPWM(2, 0, 375);
  test.setPWM(3, 0, 375);
  test.setPWM(4, 0, 375);
}
void loop() {
  int xin = map(analogRead(A0), 0, 1023, -10, 10);
  int y1in = map(analogRead(A1), 0, 1023, -10, 10);
  int y2in = map(analogRead(A2), 0, 1203, -10, 10);
  int zin = map(analogRead(A3), 0, 1023, 150, 600);
  int gin = map(analogRead(A6), 0, 1023, 200, 525);
  test.setPWM(4, 0, gin);
  delay(2);
  test.setPWM(3, 0, zin);
  delay(2);
  //Serial.println(xin);
  //Serial.println(y1in);
  //Serial.println(y2in);
  //Serial.println(zin);
  //Serial.println(gin);
  if (digitalRead(4) == LOW) resetmotor();
  if (xin >= 5) 
  {
    Serial.println("X+");
    if (xcount < 600)
    {
      xcount++;
      test.setPWM(0, 0, xcount);
      delay(2);
    }
  }
  else if (xin <= -5) 
  {
    Serial.println("X-");
    if (xcount > 150)
    {
      xcount--;
      test.setPWM(0, 0, xcount);
      delay(2);
    }
  }
  if (y1in >= 5) 
  {
    Serial.println("Y+");
    if (y1count < 600)
    {
      y1count++;
      test.setPWM(1, 0, y1count);
      delay(2);
    }
  }
  else if (y1in <= -5) 
  {
    Serial.println("Y-");
    if (y1count > 150)
    {
      y1count--;
      test.setPWM(1, 0, y1count); 
      delay(2);
    }
  }
   
  if (y2in >= 5) 
  {
    Serial.println("Y2+");
    if (y2count < 600)
    {
      y2count++;
      test.setPWM(2, 0, y2count);
      delay(2);
    }
  }
  else if (y2in <= -5) 
  {
    Serial.println("Y2-");
     if (y2count > 150)
     {
        y2count--;
        test.setPWM(2, 0, y2count);
        delay(2);
     }
  }
  /*
  if (zin >= 5) 
  {
    Serial.println("Z+");
    if (zcount < 600)
    {
      zcount++;
      test.setPWM(3, 0, zcount); 
      delay(2);
    }
  }
  
  else if (zin <= -5) 
  {
    Serial.println("Z-");
    if (zcount > 150)
    {
      zcount--;
      test.setPWM(3, 0, zcount);
      delay(2);
    }
  }
  */
  
  //motor();
}
