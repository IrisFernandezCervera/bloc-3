int TrigPin=8;
int EchoPin=9;

long duration;            //temps d'anada i tornada

int cm=0;             //posar el valor obtingut a cm


void setup() {

  Serial.begin(9600)
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

}

void loop() {

  digitalWrite(TrigPin, LOW);           //el desactivem per activar-lo més tard
  delayMicroseconds(2);

  digitalWrite(TrigPin, HIGH);        // l'activem amb un pols de 10microsegons.
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration=pulseIn (EchoPin, HIGH);   //esperem l'arribada d'un pols HIGH

  duration=duration/2;                //dividim el temps en 2


  cm = duration/29;                 //la velocitat del so es de 340 m/s, el pin echo entrega un pols de 29 microsegons.
  Serial.print("Distància:");        //per cada centímetre on es trobi l'objecta 
  Serial.println(cm);
  delay(100)

}
