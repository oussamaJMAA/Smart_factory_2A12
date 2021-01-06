#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//char array1[]="Les Machines";
//char array2[]="Tout les equippement sont marcher                               ";
int tim=500;
int buttonState = 0;
char  data ; 
int x ;


LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {


Serial.begin(9600);

  
  // put your setup code here, to run once:
  lcd.begin();
lcd.print("test test");
}

void loop() {
  // put your main code here, to run repeatedly:
 
 if(Serial.available())
  {
    data=Serial.read();
   if(data=='1')
   {
    Serial.write('1');
    
    lcd.setCursor(4,0);
    lcd.clear();
    lcd.print("Tapis");
    //lcd.clear();
    lcd.setCursor(0,1);
    }
  
  else if(data=='0')
    {
    lcd.clear();
    lcd.print("wapana");
    Serial.write('0');
    }
   }
//Serial.print(

}
