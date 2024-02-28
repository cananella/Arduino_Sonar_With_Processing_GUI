#include <Servo.h>
Servo servo;

int trig = 4, echo = 5;
int servo_pin = 7, angle = 0, i = 1;
long duration, distance;
void setup() {
  Serial.begin(9600);
  Serial.println("Radar Start");
  servo.write(angle);
  servo.attach(servo_pin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}
long dist_calc(int angle);
void loop() {
  for (angle=0; angle<=179; angle+=1){
    servo.write(angle);
    delay(20);
    long dist = dist_calc(angle);
    Serial.print(String(angle)+","+String(dist)+".");
  }
  for (angle=179; angle>=0; angle-=1){
    servo.write(angle);
    delay(20);
    long dist = dist_calc(angle);
    Serial.print(String(angle)+","+String(dist)+".");
  }
}
long dist_calc(int angle){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); //trig HIGH ~ echo HIGH
  distance = (duration * 343 / 10000) / 2;  //cm

//
//  Serial.print("Angle: ");
//  Serial.print(angle);
//  Serial.print(", Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
  return distance;
}