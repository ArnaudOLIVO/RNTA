//--MOTEUR A--
int ENA=10;
//Connecté à Arduino pin9 (sortie PWM)
int IN1=5;
//Connecté à Arduino pin4
int IN2=4;
//Connecté à Arduino pin 5

//--MOTEUR B--
int ENB=11;
//Connecté à Arduino pin 10 (Sortie PWM)
int IN3=3;
//Connecté à Arduino pin6
int IN4=2;
//Connecté à Arduino pin7


void setup(){
  pinMode(ENA,OUTPUT);
  //Configurer
  pinMode(ENB,OUTPUT);
  //les broches
  pinMode(IN1,OUTPUT);
  //comme sortie
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(ENA,LOW);
  // Moteur A - Ne pas tourner
  
  digitalWrite(ENB,LOW);
  // Moteur B - Ne pas tourner
  
  //Direction du Moteur A
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  // Direction du Moteur B
  //NB : en sens inverse du moteurA
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void loop(){
  //Direction du Moteur A
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  //MoteurA-Plein régime
  analogWrite(ENA,255);
  

  // Direction du Moteur B
  //NB : en sens inverse du moteurA
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  //MoteurB-Plein-régime
  analogWrite(ENB,255);

  delay(1000);

  //Direction du Moteur A
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  //MoteurA-Pleinrégime
  analogWrite(ENA,255);
  

  // Direction du Moteur B
  //NB : en sens inverse du moteurA
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  //MoteurB-Plein-régime
  analogWrite(ENB,255);

  delay(1000);
  //1.3 une seul roue tourne dans un sens

  //1.5 Les roues patinent et la voiture va dans tout les sens.
  
}
