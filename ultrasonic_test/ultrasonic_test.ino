int trigger = 2; 
int echo = 3; 
int buzzer = 5; 
int distance ; 
long duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Ultrasonic sensor initialisation
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  digitalWrite(trigger,LOW);
  delayMicroseconds(10);
  digitalWrite (trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigger, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration * 0.034) / 2;
  Serial.print(distance);
  // put your main code here, to run repeatedly:

}
