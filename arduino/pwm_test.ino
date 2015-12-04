
char buff = '0';

void setup() {
  pinMode(11, OUTPUT); //Lock PWM pin
}

void loop() {
  if(Serial.available() > 0) {
    buff = Serial.read();
    if(buff == 'a') {
       //lock
       for(int i = 0; i < 1000; i++) {      
         digitalWrite(11, HIGH);
         delayMicroseconds(1200);
         digitalWrite(11, LOW);
         delayMicroseconds(1800);
         Serial.flush();
       }
    }
    if(buff == 'b') {
       //unlock
       for(int i = 0; i < 1000; i++) {
         digitalWrite(11, HIGH);
         delayMicroseconds(1800);
         digitalWrite(11, LOW);
         delayMicroseconds(1200);
         Serial.flush();
       }
     }
   }
 }
