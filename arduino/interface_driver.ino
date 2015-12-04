int len = 0;
int tempSet = 20;
int voltRead = 0;
float tempRead = 0.0;
char buff[4] = "000";
char temp[3] = "00";

void setup() {
  pinMode(11, OUTPUT); //Lock PWM pin
  pinMode(7, OUTPUT);  //Relay0 digital pin
  pinMode(8, OUTPUT);  //Relay1 digital pin
  pinMode(A0, INPUT);  //Thermistor analog pin
  Serial.begin(9600);  //set Baud rate to 9600
}

void loop() { 
  if(Serial.available() > 0) {
    len = Serial.readBytes(buff, 4);
    if(buff[0] == 'a') {
       //lock
       for(int i = 0; i < 1000; i++) {      
         digitalWrite(11, HIGH);
         delayMicroseconds(1200);
         digitalWrite(11, LOW);
         delayMicroseconds(1800);
       }
    }
    if(buff[0] == 'b') {
       //unlock
       for(int i = 0; i < 1000; i++) {
         digitalWrite(11, HIGH);
         delayMicroseconds(1800);
         digitalWrite(11, LOW);
         delayMicroseconds(1200);
       }
     }
     if(buff[0] == 'c') {
       digitalWrite(7, HIGH);
     }
     if(buff[0] == 'd') {
       digitalWrite(7, LOW);       
     }
     if(buff[0] == 'e') {
       for(int i = 0; i < (len - 1); i++) {
         temp[i] = buff[i+1];
       }
     tempSet = (temp[0] - '0') * 10;
     tempSet += (temp[1] - '0');
     }
   }
   voltRead = analogRead(A0);
   tempRead = ((1023.0 - voltRead) / 1023.0) * 40.0;
   if(tempRead > tempSet) {
     digitalWrite(8, HIGH);
   }
   else {
     digitalWrite(8, LOW);
   }
 }
