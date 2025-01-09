#define ledPin 6    // Define the LED pin as pin 6
#define buzzPin 5    // Define the LED pin as pin 6
int ledState = LOW;
int buzzState = LOW;


void setup() {
  // put your setup code here, to run once:
  noInterrupts();
  TCCR1A = 0;       //Reset entire TCCR1A register
  TCCR1B = 0;       //Reset entire TCCR1B register
  TCCR1B |= B00000010;  //Set CS12 and CS10 to 1 so we get prescalar = 1024
  TIMSK1 |= B00000010;  //Set OCIE1A to 1 so we enable compare match A
  // OCR1A = 65534;    // setting the OCR 
  OCR1A = 3200;    // setting the OCR 
  
  TCCR0A = 0;       //Reset entire TCCR1A register
  TCCR0B = 0;       //Reset entire TCCR1B register
  TCCR0B |= B00000101;  //Set CS12 and CS10 to 1 so we get prescalar = 1024
  TIMSK0 |= B00000010;  //Set OCIE1A to 1 so we enable compare match A
  // OCR1A = 65534;    // setting the OCR 
  OCR0A = 50;    // setting the OCR 

  interrupts();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2);
}

// ISR
ISR(TIMER1_COMPA_vect){
  TCNT1  = 0;                  //First, set the timer back to 0 so it resets for next interrupt
  // ledState = !ledState;      //Invert LED state
  // digitalWrite(ledPin, ledState);  //Write new state to the LED on pin D5
  buzzState = !buzzState;      //Invert LED state
  digitalWrite(buzzPin, buzzState);  //Write new state to the LED on pin D5
}

ISR(TIMER0_COMPA_vect){
  TCNT0  = 0;                  //First, set the timer back to 0 so it resets for next interrupt
  buzzState = !buzzState;      //Invert LED state
  digitalWrite(buzzPin, buzzState);  //Write new state to the LED on pin D5
}
