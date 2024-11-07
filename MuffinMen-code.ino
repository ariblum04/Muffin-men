#include <Servo.h>

//setup for copper tape switchs
const int switchPin1 = 1;
const int switchPin2 = 2;
const int switchPin3 = 3;
const int switchPin4 = 4;
const int switchPin5 = 5;
const int switchPin6 = 6;
int switchVal1;
int switchVal2;
int switchVal3;
int switchVal4;
int switchVal5;
int switchVal6;

//servo set ups
Servo tableServo; 
Servo mirrorServo;
Servo floorServo;
Servo happyServo;

//led set up
const int ledPin1 = 7;
const int ledPin2 = 8;
const int ledPin3 = 9;

void setup() {
  //set switches as inputs
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);
  pinMode(switchPin5, INPUT);
  pinMode(switchPin6, INPUT);

  //set servo as outputs
  tableServo.attach(10); // pin 10
  mirrorServo.attach(11); // pin 11
  floorServo.attach(12); // pin 12
  happyServo.attach(13); // pin 13

  //set leds as outputs
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  switchVal1 = digitalRead(switchPin1);
  switchVal2 = digitalRead(switchPin2);
  switchVal3 = digitalRead(switchPin3);
  switchVal4 = digitalRead(switchPin4);
  switchVal5 = digitalRead(switchPin5);
  switchVal6 = digitalRead(switchPin6);


}
