#include <Stepper.h>
#include <Servo.h>

const int STEPS_PER_REV = 2048;      // Pasos por vuelta completa
Stepper myStepper(STEPS_PER_REV, 8, 9, 10, 11);

Servo miServo;

int horizontal = 2048;
int vertical = 46;

void setup() {
  miServo.attach(6); 

  myStepper.setSpeed(6);   
  myStepper.step(horizontal);
  
  miServo.write(vertical); 

}

void loop() {
  // No hacemos nada más
}

 
