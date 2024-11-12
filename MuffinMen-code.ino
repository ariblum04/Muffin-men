#include <Servo.h>

// Initialize switches
const int switchPin1 = 2;  // Farquaad circle
const int switchPin2 = 3;  // Gingerbread in trash
const int switchPin3 = 4;  // Farquaad at mirror
const int switchPin4 = 5;  // Princess choice 1
const int switchPin5 = 6;  // Princess choice 1
const int switchPin6 = 7;  // Princess choice 1


// Initialize LEDs
const int ledRed1 = 8;
const int ledRed2 = 9;
const int ledGreen = 10;

// Initialize variables to track positions and choices
bool Farquaad_Position = false;
bool Gingerbread_Position = false;

// Initialize Servos
Servo tableServo;    // Reveal table
Servo mirrorServo;   // Rotate mirror
Servo flapServo;     // Spin up flap
Servo fireworkServo;      // Flip up fireworks

void setup() {
  // Set up switches as inputs
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);
  pinMode(switchPin5, INPUT);
  pinMode(switchPin6, INPUT);


  // Set up LEDs as outputs
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // Attach servos to their respective pins
  tableServo.attach(11);     // Servo pin 9
  mirrorServo.attach(12);    // Servo pin 10
  flapServo.attach(13);      // Servo pin 11
  fireworkServo.attach(14);       // Servo pin 12

  // Initialize all components to default positions
  tableServo.write(0);
  mirrorServo.write(0);
  flapServo.write(0);
  fireworkServo.write(0);

  // Initialize LEDs as off
  digitalWrite(ledRed1, LOW);
  digitalWrite(ledRed2, LOW);
  digitalWrite(ledGreen, LOW);
  
  Serial.begin(9600); // For debugging
}

void loop() {
  switchVal1 = digitalRead(switchPin1);
  switchVal2 = digitalRead(switchPin2);
  switchVal3 = digitalRead(switchPin3);
  switchVal4 = digitalRead(switchPin4);
  switchVal5 = digitalRead(switchPin5);
  switchVal6 = digitalRead(switchPin6);

  
}
