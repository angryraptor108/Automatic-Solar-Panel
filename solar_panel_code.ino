#include <Stepper.h>
int stepper = 2048;
int motSpeed = 10;
int dt = 500;
int turn = 28;

#include <Servo.h>
int servop = 2;
int servoi = 30;
int servot = 35;
Servo servo;

int lightp = A1;

int light;
int lightnew;

int sl;
int sln;



Stepper myStepper(stepper, 8, 10, 9, 11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);

  servo.attach(servop);
  servo.write(servoi);

  pinMode(lightp, INPUT);


}

void loop() {


  light = analogRead(lightp);

  myStepper.step(turn);

  lightnew = analogRead(lightp);

if (lightnew < light) {
  myStepper.step(-turn);

  }
  

  while (lightnew > light) {

    light = lightnew;

    myStepper.step(turn);

    lightnew = analogRead(lightp);  
    
    }



  sl = analogRead(lightp);

  servo.write(60);

  sln = analogRead(lightp);

if (sln < sl) {
  servo.write(servot-5);

  }
  
servot = 60;
  while (sln > sl) {

    sl = sln;

    servot += 20;

    servo.write(servot);

    sln = analogRead(lightp);  
    
    }

delay(3000);


  
}
