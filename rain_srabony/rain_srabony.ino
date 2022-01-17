const int rain= 2;


void setup() {
 pinMode(rain,INPUT);
 Serial.begin(9600);
}

void loop() {
  int isRain=analogRead(rain);
  Serial.println(isRain);
}
