#include <Servo.h>

// Variables for tracking placement
bool farquadPlace1 = false;
bool gingerbreadPlace = false;
bool farquadPlace2 = false;
bool farquadPlace3 = false;

// Initialize switches
const int switchPin1 = 4;   // Farquaad start circle
const int switchPin2 = 6;   // Gingerbread in trash
const int switchPin3 = 8;   // Farquad mirror circle
const int switchPin4 = 9;  // Farquad final spot

// Initialize Servos
Servo tableServo;   // Table servo
Servo mirrorServo;  // Mirror servo
Servo flapServo;    // Flap servo
Servo ringServo;    //ring servo

void setup() {
  // Set up the switch pins as inputs
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);

  // Attach the servo motors to their pins
  tableServo.attach(5);   // Table servo on pin 5
  mirrorServo.attach(7);  // Mirror servo on pin 7
  flapServo.attach(13);
  ringServo.attach(12);

  // Initialize servos to default positions
  tableServo.write(0);
  mirrorServo.write(0);
  flapServo.write(0);
  ringServo.write(0);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Check if the first switch has been activated (Farquaad on the table)
  if (digitalRead(switchPin1) == HIGH) {
    //Serial.println("ON1");
    farquadPlace1 = true;  // Update the boolean for Farquaad's position
  }

  // Control the table servo based on Farquaad's placement
  if (farquadPlace1) {
    tableServo.write(70);  // Rotate the table servo to 70 degrees
  } else {
    tableServo.write(0);  // Keep table servo at 0 degrees (original position)
  }

  // Check if the second switch has been activated (Gingerbread in trash)
  if (digitalRead(switchPin2) == HIGH) {
    //Serial.println("ON2");
    gingerbreadPlace = true;  // Update the boolean for Gingerbread's placement
  }

  // Control the mirror servo if both conditions are true
  if (gingerbreadPlace && farquadPlace1) {
    mirrorServo.write(180);  // Rotate the mirror servo to 180 degrees
  } else {
    mirrorServo.write(0);  // Keep the mirror servo at 0 degrees (original position)
  }

  // Check if the third switch has been activated (farquad in front of mirror)
  if (digitalRead(switchPin3) == HIGH && gingerbreadPlace) {
    //Serial.println("ON3");
    farquadPlace2 = true;  // Update the boolean for Gingerbread's placement
  }

  // Control the mirror servo if both conditions are true
  if (farquadPlace2 && gingerbreadPlace) {
    flapServo.write(98);  // Rotate the mirror servo to 180 degrees
    delay(50);
    flapServo.write(0);
  } else {
    flapServo.write(0);  // Keep the mirror servo at 0 degrees (original position)
  }

    // Check if the third switch has been activated (farquad in front of mirror)
  if (digitalRead(switchPin4) == HIGH) {
    //Serial.println("ON4");
    farquadPlace3 = true;  // Update the boolean for Gingerbread's placement
  }

  if (farquadPlace3 && farquadPlace2) {
    ringServo.write(100);
  } else {
    ringServo.write(0);
  }
}
