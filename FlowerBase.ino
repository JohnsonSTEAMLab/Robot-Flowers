#include <Servo.h>;
Servo myServo;
int fullyOpen = 100;
int fullyClosed = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(3);
myServo.write(0);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(10) == 0){
  openFlower();
}
if(digitalRead(11) == 0){
  closeFlower();
  Serial.println("yep");
}
}

void openFlower(){
  for(int i = fullyClosed; i <= fullyOpen; i++){
    myServo.write(i);
    delay(20);
  }
}

void closeFlower(){
    for(int i = fullyOpen; i >= fullyClosed; i--){
    myServo.write(i);
    delay(20);
  }
}
