// LED pin assignments
const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;
const int bluePin = 4;
const int ledPins [] = { redPin, yellowPin, greenPin, bluePin }; 

// Button pin assignments
const int redBtnPin = 12;
const int yellowBtnPin = 11;
const int greenBtnPin = 10;

// State variable to hold current color pin number when holdEnabled is LOW
int currentLight;
int redState;
int yellowState; 
int greenState;

// Switch pin assignment and state variable
const int holdSwitchPin = 2;
int holdEnabled;
int prevHoldEnabled;

void setup() {

    Serial.begin(9600);

    // LED Pin Setup
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // LED Button Setup
    pinMode(redBtnPin, INPUT_PULLUP);
    pinMode(yellowBtnPin, INPUT_PULLUP);
    pinMode(greenBtnPin, INPUT_PULLUP);

    redState = LOW;
    yellowState = LOW;
    greenState = LOW;

    // Switch pin assignment and variable declaration
    pinMode(holdSwitchPin, INPUT_PULLUP);
    holdEnabled = LOW;
    prevHoldEnabled = LOW;
}

void loop() {

    // Read the state of the switch for holding the buttons
    delay(20);
    holdEnabled = digitalRead(holdSwitchPin);
    Serial.println(holdEnabled); 

    // TODO: Add in delay to dampen the noise
    if (holdEnabled == HIGH) {

      // Turn off lights when the switch is changed 
      if (prevHoldEnabled != holdEnabled) {
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
      }

      currentLight = 0;

      prevHoldEnabled = holdEnabled;
      digitalWrite(bluePin, HIGH);

      // Read the state of the buttons for the LEDs
      redState = digitalRead(redBtnPin) - 1;
      yellowState = digitalRead(yellowBtnPin) - 1;
      greenState = digitalRead(greenBtnPin) - 1;

      digitalWrite(redPin, abs(redState));
      digitalWrite(yellowPin, abs(yellowState));
      digitalWrite(greenPin, abs(greenState));
    }
    else {
        digitalWrite(bluePin, LOW);
        
        // Read the state of the buttons for the LEDs
        redState = digitalRead(redBtnPin) - 1;
        yellowState = digitalRead(yellowBtnPin) - 1;
        greenState = digitalRead(greenBtnPin) - 1;

        if (abs(redState) == HIGH) {
          currentLight = redPin;
          digitalWrite(yellowPin, LOW);
          digitalWrite(greenPin, LOW);
        }
        
        if (abs(yellowState) == HIGH) {
           currentLight = yellowPin;
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);          
        }
        
        if (abs(greenState) == HIGH) {
          currentLight = greenPin;
          digitalWrite(redPin, LOW);
          digitalWrite(yellowPin, LOW);          
        }

        digitalWrite(currentLight, HIGH);

        delay(10);
    }
}