
// defines pins numbers
const int trigf = A2;
const int echof = A3;
// defines variables
long timef,timel,timer;
int i,distf,distl,distr;

void setup() {
  //  pin gula input/ Output thik kora hoise
pinMode(trigf, OUTPUT); 
pinMode(echof, INPUT); 

Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigf, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigf, HIGH);
delayMicroseconds(10);
digitalWrite(trigf, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
timef = pulseIn(echof,HIGH);
// Calculating the distance for front SONA
distf= timef*0.034/2;



// Prints the distance on the Serial Monitor
Serial.print("Distance In centi meter: \n");
Serial.print("frnt= ");
Serial.println(distf);
delay(500);
}
