#include<Servo.h>
Servo lr;
const int ldrL=A2;
const int ldrR=A3;
int cur=90;


//A3 niche A4 upore
void setup() {
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  lr.attach(A4);
  for(int i=0;i<=90;i++)
      {
        lr.write(i);
        delay(15);
      }
  
  Serial.begin(9600);

  
}

void loop() {  

  int x1= analogRead(ldrL);
  int x2= analogRead(ldrR);

   if(cur<2)
   cur++;
   else if(cur>178)
   cur--;
   
  if((x1-x2)<-20)
    lr.write(--cur);
    
  else if((x1-x2)>20)
  lr.write(++cur);
   
  Serial.print("LDR1 :");
  Serial.println(x1);
  Serial.print(" LDR2  :");
 Serial.println(x2);
  Serial.print("curr:");
   Serial.println(cur);

  delay(20);  

}
