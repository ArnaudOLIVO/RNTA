//Moteur pas à pas 
#include<Stepper.h>
const int nombrePas= 32*64;
Stepper MoteurPaP(nombrePas, 17, 15, 16, 14);


void setup() {
  // put your setup code here, to run once:
  //Moteur Pas à pas
  MoteurPaP.setSpeed(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  MoteurPaP.step(nombrePas);
  delay(2000);
  MoteurPaP.step(-nombrePas);
  delay(2000);
}
