// A basic robot flower program that drives
// the flower via button presses

#include <Servo.h>        //tell Arduino that we want to use the servo library
Servo flowerMotor;        // create a servo object called flowerMotor

void setup() {
  Serial.begin(9600);     //start serial communication
  flowerMotor.attach(3);  //attach flowerMotor to pin 3 (tricorder servo header)
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
    
if(digitalRead(10) == 0){
  openFlower();
  delay(100);
}
if(digitalRead(11) == 0){
  closeFlower();
  delay(100);
}
}

void openFlower(){
flowerMotor.write(75);      // USE 10. At 0, the motor is pulling against
                            // flower model, causing strain damage. 
                            // USE 75 for open, more than that will take gears
                            // out of contact. 
}

void closeFlower(){
flowerMotor.write(10);
}
