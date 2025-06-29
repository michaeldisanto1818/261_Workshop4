#include <Servo.h>

//these are the two servos
Servo myservo1;
Servo myservo2;

int currentSpeedPercent = 0;

//this is the setup code
void setup() {

Serial.begin(9600);

myservo1.attach(11); //configure digital pin 11 to control the servo

myservo2.attach(9); //configure digital pin 9 to control the servo

Serial.println("Enter angle (0-180 degrees) for position servo: ");
Serial.println("OR enter speed (-100 to 100) for continuous rotation servo: ");
}

void posServo(){
if (Serial.available()) {
int angle = Serial.parseInt();
if (angle >= 0 && angle <=180) {
myservo1.write(angle);
Serial.print("Position servo moved to: ");
Serial.print(angle);
} else {
Serial.println("Invalid angle. Enter a value between 0 and 180.");
}
}
}

void rotServo() {
if (Serial.available()) {
int speedPercent = Serial.parseInt();
if (speedPercent >= -100 && speedPercent <= 100) {
int stop = 93; // Adjust this if it still spins slightly
int servoSignal;

if (speedPercent > 0) {
servoSignal = map(speedPercent, 0, 100, stop, 180);
} else if (speedPercent < 0) {
servoSignal = map(speedPercent, -100, 0, 0, stop);
} else {
servoSignal = stop; // Stop
}

myservo2.write(servoSignal);
Serial.print("Continuous servo speed set to: ");
Serial.print(speedPercent);
Serial.println("%");
} else {
Serial.println("Invalid speed. Enter a value between -100 and 100.");
}
}
}

void loop() {
// Call the function for each part of the lab here to run

//posServo(); //For Position Servo
rotServo(); //For Continuous Rotation Servo
delay(50);

}
