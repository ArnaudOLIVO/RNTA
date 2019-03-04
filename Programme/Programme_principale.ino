// Module Bluetooth
#include<SoftwareSerial.h>
#define RX 8
#define TX 9
SoftwareSerial BlueT(RX,TX);
char Data;
int distance;

//--MOTEUR A--
int ENA=10;
//Connecté à Arduino pin10 (sortie PWM)
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
int PWM=0;

//Capteur infrarouge
const int gauche=6;
const int droite=12;
const int derriere=7;
int valG=0;
int valD=0;
int valDe=0;

//Moteur pas à pas 
#include<Stepper.h>
const int nombrePas= 32*64;
Stepper MoteurPaP(nombrePas, 17, 15, 16, 14);

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
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
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  // Direction du Moteur B
  //NB : en sens inverse du moteurA
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  // Bluetooth et Serial
  //pinMode(14,OUTPUT);
  //digitalWrite(14,HIGH);
  Serial.begin(9600);
  BlueT.begin(9600);
  Serial.println("Bonjour -Pret pour les commandes AT");

  //Capteur infrarouge
  pinMode(gauche,INPUT);
  pinMode(droite,INPUT);
  pinMode(derriere,INPUT);

  //Moteur Pas à pas
  MoteurPaP.setSpeed(8);

  delay(1000);
}



void loop() {
  // put your main code here, to run repeatedly:
   
   if (BlueT.available()){
    Data=BlueT.read();
    Serial.println(Data);
    delay(50);}


valG=digitalRead(gauche);
valD=digitalRead(droite);
valDe=digitalRead(derriere);
   //Capteur infrarouge
  if(valG==1 or valD==1 or valDe==1){
    analogWrite(ENA,0);
    analogWrite(ENB,0);

    // marche arrière pour sortir du mauvais pas
    //Direction du Moteur A
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    // Direction du Moteur B
    //NB : en sens inverse du moteurA
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENA,255);
    analogWrite(ENB,255);
    Serial.println("Help");
    delay(10);
  }
  else {
 
  //EN Avant
//  if (Data=='C') {
  //  //Direction du Moteur A
    //digitalWrite(IN1,LOW);
 //   digitalWrite(IN2,HIGH);
    // Direction du Moteur B
    //NB : en sens inverse du moteurA
  //  digitalWrite(IN3,HIGH);
    //digitalWrite(IN4,LOW);  }
  
    //En Arrière 
 // if (Data=='c') {
 //   //Direction du Moteur A
 //   digitalWrite(IN1,HIGH);
   // digitalWrite(IN2,LOW);
    // Direction du Moteur B
    //NB : en sens inverse du moteurA
   // digitalWrite(IN3,LOW);
 //   digitalWrite(IN4,HIGH);}
  
  //Moteur PWM 
  if (Data=='A') {
    PWM=BlueT.parseInt();
    Serial.println(PWM);
    delay(10); }

  //Avancer tout droit 
  if (Data=='F') {
    //Direction du Moteur A
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    // Direction du Moteur B
    //NB : en sens inverse du moteurA
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM);
    Serial.println("F");
    delay(10); }

  //Tourner à Droite 
  if (Data=='R') {
    analogWrite(ENA,PWM);
    analogWrite(ENB,0);
    Serial.println("R");
    delay(10); 
    }

  //Tourner à Gauche 
  if (Data=='L') {
    analogWrite(ENA,0);
    analogWrite(ENB,PWM);
    Serial.println("L");
    delay(10); 
    }
  

  
  // Vers l'arrière
  if (Data=='B') {
    //Direction du Moteur A
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    // Direction du Moteur B
    //NB : en sens inverse du moteurA
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENA,PWM);
    analogWrite(ENB,PWM);
    Serial.println("B");
    delay(10);
  }
  // Affichage 
  BlueT.print(String("*D"+String(PWM)+"*"));



  //Moteur Pas à pas
  if (Data=='P') {
    MoteurPaP.step((nombrePas/360)*280);
    delay(1000);
    MoteurPaP.step(-(nombrePas/360)*280);
    delay(1000);
  }



}
}
