
#include<dht.h>

#include<Servo.h>
Servo baal;

String x;
bool on=0, off=1;
int i,j,a,b,cd;
void setup() {
  baal.attach(9);
  Serial.begin(9600);
 /* for(i=90;i>=0;i--)
      {
        baal.write(i);
        delay(15);
      }*/
}

void loop() {
  if(Serial.available())
  {
    x=Serial.read();
    a=x.toInt()-48;
    
    Serial.println(a);

    if(a==0&&on==1)
    {
      for(i=90;i<=180;i++)
      {
        baal.write(i);
        delay(15);
      }
      //delay(20000);
      on=0;
    }
    
    else if(a==1&&on==0)
    {
      for(i=180;i>=90;i--)
      {
       baal.write(i);
       delay(15);
      }
      //delay(20000);
      on=1;
    }
    
    
    
    }
  

}
