#define buttonPin 2 // define the button pin as pin 2
#define ledPin 6    // Define the LED pin as pin 6


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE); // Starting an interrupt for the pushButton
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(2); // delay as a placeholder
}

// Interrupt service Routine:
void buttonInterrupt() {
  if(digitalRead(buttonPin) == HIGH)
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  else
    digitalWrite(ledPin, LOW);   // turn the LED on (HIGH is the voltage level)
}
