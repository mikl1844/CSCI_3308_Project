int len = 0;
int tempSet = 20;
int voltRead = 0;
float tempRead = 0.0;
char buff[3] = "00";

void setup() {
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    len = Serial.readBytes(buff, 3);
    tempSet = (buff[0] - '0') * 10;
    tempSet += (buff[1] - '0');
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
