#include <Servo.h>

//Variable for reading the switch status
int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;
int switchState4 = 0;
int switchState5 = 0;
int switchState6 = 0;

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
Servo ringServo;      // Flip up fireworks

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
  tableServo.attach(8);     // Servo pin 9
  mirrorServo.attach(9);    // Servo pin 10
  flapServo.attach(10);      // Servo pin 11
  ringServo.attach(11);       // Servo pin 12

  // Initialize all components to default positions
  tableServo.write(0);
  mirrorServo.write(0);
  flapServo.write(0);
  ringServo.write(0);

  // Initialize LEDs as off
  digitalWrite(ledRed1, LOW);
  digitalWrite(ledRed2, LOW);
  digitalWrite(ledGreen, LOW);
  
  Serial.begin(9600); // For debugging
}

void loop() {
  //if farquaad is placed by the table the table drops
  switchState1 = digitalRead(switchPin1);
  if (switchPin1 == HIGH){
    tableServo.write(90); //should rotate 90 degrees
  } else {
    tableServo.write(0);
  }

  //if the gingerbreadman is placed in trash the mirror spins
  switchState2 = digitalRead(switchPin2);
  if (switchPin2 == HIGH){
    mirrorServo.write(180);
  } else {
    mirrorServo.write(0);
  }

  //if farquaad is placed by the mirror, the secret pannel opens
  switchState3 = digitalRead(switchPin3);
  if (switchPin3 == HIGH){
    flapServo.write(90);
  } else {
    flapServo.write(0);
  }
  
//   //if farquaad is on the wrong princess (snow white)
//   switchState4 = digitalRead(switchPin4);
//   if (switchState4 == HIGH){
//     digitalWrite(ledRed1, HIGH);
//   } else {
//     digitalWrite(ledRed1, LOW);
//   }

//   //if farquaad is on the wrong princess (aurora)
//   switchState5 = digitalRead(switchPin5);
//   if (switchState5 == HIGH){
//     digitalWrite(ledRed2, HIGH);
//   } else {
//     digitalWrite(ledRed2, LOW);
//   }
  
//if farquaad is on the right princess
  switchState6 = digitalRead(switchPin6);
  if (switchState6 == HIGH){
    digitalWrite(ledGreen, HIGH);
    ringServo.write(90);
  } else {
    digitalWrite(ledGreen, LOW);
    ringServo.write(0);
  }

  
  
}
