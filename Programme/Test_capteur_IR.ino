const int gauche=6;
const int droite=12;
const int derriere=7;
int valG=0;
int valD=0;
int valDe=0;



void setup() {
  // put your setup code here, to run once:
  pinMode(gauche,INPUT);
  pinMode(droite,INPUT);
  pinMode(derriere,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valG=digitalRead(gauche);
  Serial.println("G ="+String(valG));
  valD=digitalRead(droite);
  Serial.println("D ="+String(valD));
  valDe=digitalRead(derriere);
  Serial.println("F ="+String(valDe));
  delay(100);
  
}
//Quand la distance est trop grande ou que le suport est noire mate, les detecteur ne renvoie 1.
//Il renvoie 0 si il reçoit la lumière.
