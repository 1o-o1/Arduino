
 const int in1= 5;
 const int in2= 6;
 const int in3= 7;
 const int in4= 8;
 const int ena= 9;
 const int enb= 10; 
 const int up3=11;
 const int lr1=12;
 const int sc5=13;
 const int trigf = A1;
 const int echof = A0;
 const int trigr = A3;
 const int echor = A2;
 const int trigl = A5;
 const int echol = A4;
 bool flag=0;
 double updn,lr,swc;
 int i,j,k,l,enbla,enblb;
 const int Tupdn=990,Tlr=1464;

 
 long timef,timer,timel;
 int distf,distr,distl;

 void forward(void);
 void backward(void);
 void stoop(void);
 int st_ck(int n);
 
void setup() {
  for(i=11;i<=13;i++)
  pinMode(i,INPUT);
  for(i=5;i<=10;i++)
  pinMode(i,OUTPUT);
  pinMode(trigr, OUTPUT); 
  pinMode(echor, INPUT); 
  pinMode(trigf, OUTPUT); 
  pinMode(echof, INPUT); 
  pinMode(trigl, OUTPUT); 
  pinMode(echol, INPUT);
  Serial.begin(9600);
}

void loop() {
  updn=pulseIn(up3,HIGH);
  lr=pulseIn(lr1,HIGH);
  swc=pulseIn(sc5,HIGH);
  /*Serial.println((String)"updown: "+updn+ " left-right: "+lr+ " SwC: "+swc );
  Serial.print(flag);
  Serial.println(" :flag .....");
  delay(200);*/
  if(swc<1200&&flag==0)
  forward();
  else if(swc<1600)
  stoop();
  else if(swc>1600)
  {flag=0;backward();}
  else if(flag==1)
  stoop();
}

void forward( void)
{
  int enabla,enablb,turn,tmp;
  enabla=enablb=(updn-Tupdn)/66*17;
  enabla=min(enabla,255);
  enablb=min(enablb,255);
  turn=(lr-Tlr)/33*17;
  if(turn>255)
  turn=255;
  else if(turn<-255)
  turn=-255;
  //Serial.println(turn);
  tmp=st_ck(turn);
  //Serial.println(tmp);
     if(tmp==1)
   {
    digitalWrite(trigr, LOW);
    delayMicroseconds(2);

    digitalWrite(trigr, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigr, LOW);
    timer = pulseIn(echor,HIGH);
   // Calculating the distance for front SONA
    distr= timer*0.034/2;
    if(distr<25)
    stoop();
    else{
     //go to right
     enabla+=turn;
     enablb-=turn;
     enabla=min(enabla,255);
     enablb=max(enablb,0);
     
      analogWrite(ena,enabla);
      analogWrite(enb,enablb);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      
    }}
    else if(tmp==-1)
   {
    digitalWrite(trigl, LOW);
    delayMicroseconds(2);

    digitalWrite(trigl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigl, LOW);
    timel = pulseIn(echol,HIGH);
   // Calculating the distance for front SONA
    distl= timel*0.034/2;
    if(distl<25)
    stoop();
    else{
     //go to left     
     enabla+=turn;
     enablb-=turn;
     enabla=max(enabla,0);
     enablb=min(enablb,255);
     
      analogWrite(ena,enabla);
      analogWrite(enb,enablb);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      
    }}
    else
    {
      
    digitalWrite(trigf, LOW);
    delayMicroseconds(2);

    digitalWrite(trigf, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigf, LOW);
    timef = pulseIn(echof,HIGH);
   // Calculating the distance for front SONA
    distf= timef*0.034/2;
    //Serial.println(distf);
   // delay(1000);
      if(distf<21)
      {analogWrite(ena,enabla);
      analogWrite(enb,enablb);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      delay(200);
      flag=1;
      }

      else
      {
      analogWrite(ena,enabla);
      analogWrite(enb,enablb);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);}

      }
  
}
void stoop(void)
   {
      analogWrite(ena,0);
      analogWrite(enb,0);
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
   }
void backward( void)
{
  int enabla,enablb,turn,tmp;
  enabla=enablb=(updn-Tupdn)/66*17;
  enabla=min(enabla,255);
  enablb=min(enablb,255);
  turn=(lr-Tlr)/33*17;
  if(turn>255)
  turn=255;
  else if(turn<-255)
  turn=-255;
  tmp=st_ck(turn);

     if(tmp==1)
   {
     //go to right
     enabla+=turn;
     enablb-=turn;
     enabla=min(enabla,255);
     enablb=max(enablb,0);
      
    }
    else if(tmp==-1)
   {
     //go to left     
     enabla+=turn;
     enablb-=turn;
     enabla=max(enabla,0);
     enablb=min(enablb,255);
      
    }
    
      analogWrite(ena,enabla);
      analogWrite(enb,enablb);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
  
}

int st_ck(int n)
{
 if(n<-9)
  return -1;
 else if(n>9)
 return 1;
 else
 return 0;
}
