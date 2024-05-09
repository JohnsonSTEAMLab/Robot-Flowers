#include <Servo.h>;
Servo myServo;
int fullyOpen = 100;
int fullyClosed = 0;
int bloomTime = 3000;
int coolDown = 10000;

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
Serial.println(analogRead(3));
 if(analogRead(3) > 500){
  Serial.println("inside if");
  openFlower();
  Serial.println("after open flower");
  delay(bloomTime);
  Serial.println("waiting for bloom to finish");
  closeFlower();
  Serial.println("cooldown");
  delay(coolDown);
  Serial.println("finished cooling down"); 
 }
if(digitalRead(10) == 0){
  //openFlower();
}
if(digitalRead(11) == 0){
  //closeFlower();
  //Serial.println("yep");
}
}

void openFlower(){
  for(int i = fullyClosed; i <= fullyOpen; i++){
    myServo.write(i);
    delay(20);
  }
}

void closeFlower(){
    Serial.println("in closeFlower");
    for(int i = fullyOpen; i >= fullyClosed; i--){
    myServo.write(i);
    delay(20);
  }
}
