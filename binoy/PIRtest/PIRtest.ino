
const int pir = A0;
const int L= 3;
const int Rel=4;
void setup() {
  // put your setup code here, to run once:
 pinMode(pir,INPUT);
 pinMode(L,OUTPUT);
 pinMode(Rel,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=digitalRead(pir);
  if(x==1)
  {digitalWrite(Rel,HIGH);
    digitalWrite(L,HIGH);
}
  else
    {digitalWrite(Rel,LOW);
      digitalWrite(L,LOW);
}

  Serial.println(x);
}
