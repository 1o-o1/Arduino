#include <dht.h>
dht ch;
const int dPin= D0;
//dht pin 2 to arduino pin 7
void setup() {
  
  //pinMode(D0,INPUT);
 Serial.begin(9600);
 
}

void loop() {

 int ba=ch.read22(dPin);
 Serial.print("Temperature :");
 Serial.println(ch.temperature);
  Serial.print("Humidity :");
 Serial.println(ch.humidity);
 
delay(200);
  
}
