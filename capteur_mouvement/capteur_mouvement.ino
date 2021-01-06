#include <LiquidCrystal_I2C.h>
const int buttonpin=2 ; //Broche du capteur PIR
const int ledpin=13 ; 
const int nbmax=20;
int buttonState = 0; 
int i=0;
int k=0;




LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 pinMode(ledpin,OUTPUT); // la broche du led est mise en sortie 
 pinMode (buttonpin,INPUT) ; // la broche du capteur est mise en entree
Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
buttonState= digitalRead(buttonpin); //lecture du capteur 



  delay(500);
if(buttonState==HIGH) // si quelquechose est detecte
{
  Serial.println("motion detected");
digitalWrite(ledpin,HIGH); // on allume la LED
k = k+1;
if(k==nbmax){

   lcd.clear();
  lcd.print("Nombre Max Has Reached!");
}
else {
Serial.println("motion ended");
  digitalWrite(ledpin,LOW); // on eteint la LED
}

delay(500);
}
}
