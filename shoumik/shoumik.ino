
// defines pins numbers
const int trigf = A1;
const int echof = A0;
const int buz = A2;
const int L= A3;
// defines variables
long timef;
int i,distf;

void setup() {
  //  pin gula input/ Output thik kora hoise
pinMode(trigf, OUTPUT); 
pinMode(echof, INPUT); 
pinMode(buz,OUTPUT);
pinMode(L,OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
digitalWrite(trigf, LOW);
delayMicroseconds(2);
digitalWrite(trigf, HIGH);
delayMicroseconds(10);
digitalWrite(trigf, LOW);
timef = pulseIn(echof,HIGH);
distf= timef*0.034/2;


if(distf>20&&distf<40)
{noTone(buz);
digitalWrite(L,LOW);
delay(200);}
else
{tone(buz,2000);
 digitalWrite(L,HIGH);
 delay(100);
  }
// Prints the distance on the Serial Monitor
Serial.print("Distance In centi meter: \n");
Serial.print("frnt= ");
Serial.println(distf);
//delay(500);
}
