const int buttonpin=2 ; //Broche du capteur PIR
const int ledpin=13 ; 
int buttonState = 0; 
void setup() {
 pinMode(ledpin,OUTPUT); // la broche du led est mise en sortie 
 pinMode (buttonpin,INPUT) ; // la broche du capteur est mise en entree
}

void loop() {
buttonState= digitalRead(buttonpin); //lecture du capteur 
if(buttonState==HIGH) // si quelquechose est detecte
{
digitalWrite(ledpin,HIGH); // on allume la LED
}
else  {

  digitalWrite(ledpin,LOW); // on eteint la LED
}
}
