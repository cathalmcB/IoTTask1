
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
 
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
const int ldrPin = 0;

 
int counter = 0;
int colorR = 200;
 int colorG = 0;
 int colorB = 0;
 
void setup()
{
  //Setup pin modes
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    
}

void on()
{
   lcd.setRGB(colorR, colorG, colorB);
        colorR = 200;
        colorG = 0;
        colorB = 0;
       
}

void off()
{
   lcd.setRGB(colorR, colorG, colorB);
        colorR = 0;
        colorG = 0;
        colorB = 0;
        
} 
void loop()
{
  int ldrRead = analogRead(ldrPin);

  while ( ldrRead > 500 )
  {
    off();
    Serial.println(ldrRead);
    lcd.print("");
    lcd.setCursor(0, 1);
    lcd.print("");
    delay(1000);
    
    //Play first section
    firstSection();
    ldrRead =analogRead(ldrPin);
    if (ldrRead < 500 )
    {
      continue;
    }
    on();
    lcd.setCursor(0, 0);
    lcd.print("Get Out of my ");
    lcd.setCursor(0, 1);
    lcd.print(" Shtufff");
    delay(1000);
    //Play second section
    secondSection();
   
    /*Variant 1
    beep(f, 250);  
    beep(gS, 500);  
    beep(f, 350);  
    beep(a, 125);
    beep(cH, 500);
    beep(a, 375);  
    beep(cH, 125);
    beep(eH, 650);
   
    delay(500);
  
   
    //Repeat second section
    secondSection();
   
    //Variant 2
    beep(f, 250);  
    beep(gS, 500);  
    beep(f, 375);  
    beep(cH, 125);
    beep(a, 500);  
    beep(f, 375);  
    beep(cH, 125);
    beep(a, 650); */ 
   
    delay(650);
    
  }
}
 
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  on();
  beep(a, 150);
  beep(aH, 500);
  off();
  beep(gSH, 325);
  beep(gH, 175);
  on();
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
  off();
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  on();
  beep(dH, 325); 
  off(); 
  beep(cSH, 175);  
  beep(cH, 125);  
  on();
  beep(b, 125); 
   
  beep(cH, 250);
  
 
  delay(350);
}






