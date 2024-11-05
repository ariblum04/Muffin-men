//confusion


int sensorVal;
//setting pin numbers
const int sensorPin = A4; // the vibration sensor is connected to analog pin A4
const int ledPin = 13;    // the LED is connected to digital pin 13
const int buttonPin = 2;  // the button is connected to digital pin 2
const int piezoPin = 10;  // the piezo is connected to digital pin 10

int buttonState = 0;
int previousButtonState = 0;
int timer = 0;

boolean buttonBool = false;  // Tracks whether the device is on or off

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);  // Vibration sensor is set as input
  pinMode(buttonPin, INPUT);  // Button is set as input
  pinMode(ledPin, OUTPUT);    // LED is set as output
  pinMode(piezoPin, OUTPUT);  // Piezo is set as output
}

void buttonCheck() {
  buttonState = digitalRead(buttonPin);  // Read the button state

  if (buttonState != previousButtonState) {
    delay(20);  // Debouncing delay
    if (buttonState == HIGH) {
      //Serial.println("Button pressed");

      buttonBool = !buttonBool;

      delay(500);  // 500ms delay after button press
    }
  }
  previousButtonState = buttonState;  // Update previous state
}

void ledLight() {
  if (buttonBool) {
    digitalWrite(ledPin, HIGH);  // Turn LED on when device is on
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off when device is off
  }
}

void piezoControl() {
  if (timer > 0) { // Keep the piezo tone for the duration of the timer
    tone(piezoPin, 1000 + timer);  // Play tone
    timer--;  // Decrement the timer smoothly
  } else {
    noTone(piezoPin);  // Stop the piezo when timer reaches 0
  }
}

void loop() {

  buttonCheck();   // Check the button state and toggle device on/off
  ledLight();      // Control the LED based on button state

  if (buttonBool) {  // Only check vibration when the device is on
    sensorVal = analogRead(sensorPin);  // Read the vibration sensor value

    if (sensorVal > 1000) {  // If vibration exceeds threshold
      timer = 600;  
    }
  } else {
    noTone(piezoPin);  // Turn off the piezo if the device is off
  }

  piezoControl();  // Handle piezo sound with smooth adjustments
}
