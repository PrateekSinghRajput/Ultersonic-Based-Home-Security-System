
//Prateek
//wwww.prateeks.in
//https://www.youtube.com/c/JustDoElectronics/videos

#include <SoftwareSerial.h>
const String PHONE = "+918830584864";
#define rxPin 2
#define txPin 3

SoftwareSerial sim800(rxPin,txPin);

#define trigPin 6
#define echoPin 7

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(115200);        

  sim800.begin(9600);
  Serial.println("SIM800L software serial initialize");

  sim800.println("AT");
  delay(1000);
}

void loop(){

while(sim800.available()){
  Serial.println(sim800.readString());
}

while(Serial.available())  {
  sim800.println(Serial.readString());
}

  long time_duration, distance_in_cm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time_duration = pulseIn(echoPin, HIGH);
  distance_in_cm = time_duration / 29 / 2;

  Serial.print(distance_in_cm);
  Serial.println(" cm");

  //if the distance is equal or less then 10 cm
  if (distance_in_cm <= 10) {
    Serial.println("Motion detected!");
    Serial.println("calling....");
    sim800.println("ATD"+PHONE+";");
    delay(20000); 
  }

  delay(500);
}
