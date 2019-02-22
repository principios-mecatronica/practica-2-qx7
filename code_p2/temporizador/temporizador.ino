int flag=LOW;
void setup() {
  Serial.begin(9600);
  DDRB = DDRB | B10000000;
  cli();
  TCCR1B= 0;
  TCCR1A=0;
  TCCR1B |= (1 << CS12);
  TCNT1= 3036;
  TIMSK1 |= (1 << TOIE1);
  sei();
}

void loop() {

}

ISR(TIMER1_OVF_vect){
  Serial.println("timer 1 overflow"); //prueba
  digitalWrite(13, flag);
  flag=!flag;
}
