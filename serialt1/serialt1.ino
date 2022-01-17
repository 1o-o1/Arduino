int i=69;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char ar[5];
  dtostrf(i,4,2,ar);
  if(Serial.available()>0)
   Serial.write(ar);
delay(500);
//i-=10;
//if(i<0)
//i=100;
   //Serial.println(i)
}
