
 double updn,lr,swc;
void setup() {
  pinMode(9,INPUT);
  Serial.begin(9600);
}

void loop() {
  updn=pulseIn(11,HIGH);
  lr=pulseIn(12,HIGH);
  swc=pulseIn(13,HIGH);
  Serial.println((String)"updown: "+updn+ " left-right: "+lr+ " SwC: "+swc );
  Serial.println(".....");
  delay(200);
  

}
