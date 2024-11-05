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

// AAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHH
