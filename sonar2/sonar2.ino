#include<Servo.h>
Servo baal;

String x;
bool on=0, lr=0;
int i,j,a,b,cd;
void setup() {
  baal.attach(A4);
  Serial.begin(9600);
  for(i=0;i<=90;i++)
      {
        baal.write(i);
        delay(15);
      }
}

void loop() {
  if(Serial.available())
  {
    x=Serial.read();
    a=x.toInt()-48;

    Serial.println(a);

    if(a==0&&on==1)
    {
      for(i=90;i>=0;i--)
      {
        baal.write(i);
        delay(50);
      }
      //delay(20000);
      on=0;lr=0;
    }
    
    else if(a==1&&on==0)
    {
      for(i=90;i<=180;i++)
      {
       baal.write(i);
       delay(50);
      }
      //delay(20000);
      on=1;
      lr=1;
    }
    else if(a==2)
    {
      if(lr==0)
      {
      for(i=0;i<=90;i++)
      {
       baal.write(i);
       delay(50);
      }}   
      else
      {
      for(i=180;i>=90;i--)
      {
       baal.write(i);
       delay(50);
      }}   
     
    
    }}
  

}
