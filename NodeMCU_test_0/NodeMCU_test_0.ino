
const int trigp=D1;
const int echop=D2;
long timep;
int i,j,k,distp;

void setup() {
  pinMode(trigp,OUTPUT);
  pinMode(echop,INPUT);
  Serial.begin(9600);
}

void loop() {
  
 
    digitalWrite(trigp, LOW);
    delayMicroseconds(2);

    digitalWrite(trigp, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigp, LOW);
    timep = pulseIn(echop,HIGH);
   // Calculating the distance for front SONA
    distp= timep*0.034/2;

    Serial.println(distp);
    delay(300);
}
