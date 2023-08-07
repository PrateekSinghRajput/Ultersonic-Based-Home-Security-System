//Prateek
//https://justdoelectronics.com
//https://www.youtube.com/@JustDoElectronics/videos

int const trigPin = 6;
int const echoPin = 7;
int const buzzPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {

  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  if (distance <= 20 && distance >= 0) {
    // Buzz
    digitalWrite(buzzPin, HIGH);
    delay(1000);
    SendSMS();
  } else {

    digitalWrite(buzzPin, LOW);
  }
  delay(60);
}
void SendSMS() {
  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  Serial.println("Sensor Detect Movement Plz Check");
  delay(200);
  Serial.println((char)26);
  delay(1000);
}
