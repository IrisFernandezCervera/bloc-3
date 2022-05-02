const int broncidor=3;
int valorLDR=0;                   //valor llegit
int freqbroncidor=0;              // variable que magatzema el to de freqüència del broncidor.

void setup() {
  pinMode (broncidor,OUTPUT);
  Serial.begin(9600);             //inicia amb el port sèrie a 9600 bauds

}

void loop() {
  valorLDR=analogRead(AD);                          //llegeix el valor

                                                   //converteix el rang de 0-1023 amb un to adeqüat pel broncidor.
  freqbroncidor= map (valorLDR, 0, 1023, 20, 5000);   //els valors poden canviar

  tone(broncidor, freqbroncidor);             // el broncidor sona amb el to anteriorment guardat adalt

  Serial.print("LDR(0-1023)=");               //escaneixa i vigila aquests valors
  Serial.print(valorLDR);
  Serial.print("\t To del so del broncidor=");
  Serial.println(freqbroncidor);

  delay(20)
  

}
