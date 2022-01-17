#include<Servo.h>

Servo sona,door,camxy,camz;

String x;
bool on=0, off=1;
const int trigf = A1;
const int echof = A0;
const int trigp = A3;
const int echop = A2;
 const int in1= 2;
 const int in2= 3;
 const int in3= 4;
 const int in4= 5;
 const int ena= 6;
 const int enb= 7;
 const int hap = 12;

// defines variables
long timef,timep;
int  distf,distp,enablb,enabla;
int i,j,a,b,cd,dist=40;
int front(void);
void percent (void);
void servOpen(void);
void servClose(void);
void gofor();
void gol();
void gor();
void runn();
void stopcar();
void setup() {
  sona.attach(9);
  door.attach(8);
  camxy.attach(10);
  camz.attach(11);
  pinMode(trigf, OUTPUT); 
  pinMode(echof, INPUT); 
  
  pinMode(trigp, OUTPUT); 
  pinMode(echop, INPUT); 
  door.write(180);
  Serial.begin(9600);
 
}

void loop() {
  
   percent();
    int per = (37-distp)*5;
    distp=22;
    if(distp==22)
    runn();
    else{
    per=distp;
    char ar[5];
    dtostrf(per,4,2,ar);
    if(Serial.available()>0)
    Serial.write(ar);
    delay(500);
    
   for(j=0;j<=180;j+=15)
   {
    sona.write(j);
    camxy.write(j);
    /*Serial.print("Sonar er servo degree :");
    Serial.println(j);
    Serial.print("sonar distance paise : ");
    Serial.println(front());*/
    if(front()<dist)
      {
     
        servOpen();
        analogWrite(hap,255);
        
        delay(3000);
        while(front()<distf)
        {delay(500);}
        }
      else
      {
        servClose();
        digitalWrite(hap,LOW);
        }
       delay(200);
    }
    
    
   for(j=180;j>=0;j-=15)
   {
    sona.write(j);
    if(front()<dist)
      {
     
        servOpen();
        digitalWrite(hap,HIGH);
        delay(3000);
        while(front()<dist)
        {delay(500);}
        }
      else
      {
        servClose();
        digitalWrite(hap,LOW);
        }
       delay(200);
    }
    
    
    
    }}
  



int front(void){
    digitalWrite(trigf, LOW);
    delayMicroseconds(2);
    digitalWrite(trigf, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigf, LOW);
    timef = pulseIn(echof,HIGH);
    distf= timef*0.034/2;
    return distf;
    }

void servOpen(void)
{
if(on==0)
    {
      for(i=180;i>=90;i--)
      {
       door.write(i);
       delay(15);
      }
      on=1;
    }
  }
void servClose(void)
{
      if(on==1)
    {
      for(i=90;i<=180;i++)
      {
        door.write(i);
        delay(15);
      }
      on=0;
    }}

void percent(void)
    {digitalWrite(trigp, LOW);
    delayMicroseconds(2);

    digitalWrite(trigp, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigp, LOW);
    timep = pulseIn(echop,HIGH);
   // Calculating the distance for front SONA
    distp= timep*0.034/2;
    
    }
 void runn (void)
 {
      if(front()>20)
      gofor();
      else 
      {
        sona.write(0);
        if(front()>20)
        gol();
        else
        {sona.write(180);
        if(front>20)
        gor();
        else
        stopcar();}
        }

  
  }
  void gofor(){
      analogWrite(ena,255);
      analogWrite(enb,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      
      delay(200);
      Serial.println("samne jaitase");
}

 void gol(){
      analogWrite(ena,255);
      analogWrite(enb,255);
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      delay(200);
} 
void gor(){
      analogWrite(ena,255);
      analogWrite(enb,255);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      delay(200);
}
void stopcar()
  {
      analogWrite(ena,255);
      analogWrite(enb,255);
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      delay(200);
      distp--;
      loop();
}
