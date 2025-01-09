int ledState = 0;
int dutyCycle = 90;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  noInterrupts();
  TCCR0A = 0;       //Reset entire TCCR1A register
  TCCR0B = 0;       //Reset entire TCCR1B register
  TCCR0B |= B00000010;  //Set CS12 and CS10 to 1 so we get prescalar = 8
  TIMSK0 |= B00000010;  //Set OCIE1A to 1 so we enable compare match A
  OCR0A = 39;    // setting the OCR 
  interrupts();
  DDRD = B01000000;  // Set pin 6 as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2);
}

// ISR
ISR(TIMER0_COMPA_vect){
  TCNT0  = 0;             //First, set the timer back to 0 so it resets for next interrupt
  if(count >= dutyCycle)       
    PORTD &= B10111111;   // Turn off LED
  else
    PORTD |= B01000000;   // Turn on LED
  
  count++;  // Increment the counter up to 100
  if (count >= 100)
    count = 0;
}
