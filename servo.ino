#include <Servo.h>

int servoPin = 8;
int servoPos=50;
int readPin = A0;
int readVal;
int sPin = 7;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(sPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  digitalWrite(sPin, HIGH);
  readVal = analogRead(readPin);
  Serial.println(readVal);
  
  myServo.write(servoPos);
  if (readVal <=5) {
    servoPos = 0;
  }
  if (readVal >=20) {
    servoPos = 180;
  }
}
