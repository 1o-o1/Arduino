// This code is made to be played with. All of the functions to control the car and the sensor are here for you to combine as you please.
// The simple go-forward-and-avoid sketch that the car is running in one of our videos (pattern) is currently in the main loop. 
// The other pattern that runs the car in a loop (pattern1) is also saved as a seperate function if you'd like to use it.


#include <Servo.h> //make sure you have this servo library downloaded

int enA = 10;  //define motor control pins
int in1 = 9;
int in2 = 8;

Servo myservo; //define steering servo and it's initial position
int pos = 90; 

Servo sensor; //define sensor servo and it's initial position
int posi = 0;

#define trigPin 13 //define sensor control pins
#define echoPin 12



void setup()
{
  myservo.attach(7); //define steering servo control pin
  sensor.attach(4);  //define sensor servo control pin
  //set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //set out for trigger pin and in for echo pin (echo relays back to board)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600); //start the serial monitor to in case you want to see what your sensor sees. Good for troubleshooting
}

// Below are the functions for autonomously controlling the car. Their names are self explanitory

// These are motor controls
// For the motor to run ENA MUST be set to high
// reversing the which IN is high/low changes the direction the motor runs

void gofor(){

  digitalWrite(enA, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
}

void goback()
{
  digitalWrite(enA, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
}

void stopcar()
  {
  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
}

// These are servo controls
// Inbetween turns could easily be made using more specific angles for the servo

void sharpl(){ 
    myservo.write(0); 
    }

void sharpr(){
  myservo.write(180); 
         }
         
 void center(){
  myservo.write(90); 
         }

// Here is our sensor code. 
//If you want, it could be helpful to mess with the sensor trigger distance a little depending on where your sensor is mounted.
// This sensor sends out a sound 'ping' and uses the time it take to return to determine distance. Like echolocation.

  void sense()
{

  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

 
  
  if (10  > distance ){
     Serial.println("STAHP");
     goback();
     sharpl();
     delay(750);}
        
  
   else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}

//This code just runs the sensor servo back and forth, allowing it so stop and sense every 45 degrees. Include this code anytime you want your car to sense.

void servo(){
sensor.write(180);
sense();
sensor.write(135);
sense();
sensor.write(90);
sense();
sensor.write(45);
sense();
sensor.write(0);
sense();
sensor.write(45);
sense();
sensor.write(90);
sense();
sensor.write(135);
sense();
}

// The simple go-forward-and-sense pattern
 void pattern(){
center();
gofor();
delay(20);
servo();
}

// The run in a circle and sense pattern

void pattern1(){
stopcar();
servo();
delay(5000);
center();
delay(20);
servo();
gofor();
delay(6500);
stopcar();
servo();
delay(500);
sharpr();
delay(100);
gofor();
delay(2750);
stopcar();
servo();
delay(500);
center();
delay(20);
servo();
gofor();
delay(3000);
stopcar();
servo();
delay(500);
sharpr();
delay(100);
gofor();
delay(2750);
center();
delay(20);
servo();
gofor();
delay(6500);
stopcar();
delay(500);
sharpr();
delay(100);
gofor();
delay(2750);
stopcar();
servo();
delay(500);
center();
delay(20);
servo();
gofor();
delay(3000);
stopcar();
servo();
delay(500);
sharpr();
delay(100);
gofor();
delay(2750);
}

//The simple go-forward-and-sense pattern is currently in the loop for you to test in your car.
void loop(){ 
pattern();
}


  

