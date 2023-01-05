#define B_1 2 //button 1 pin
#define B_2 3 //button 2 pin
#define RED 8 //red LED pin
#define GREEN 9 //green LED pin
#define BLUE 10 //blue LED pin
volatile byte flag=0; //flag designated as volatile byte since it is used in ISR
void setup()
{
    pinMode(RED,OUTPUT); 
    pinMode(GREEN,OUTPUT);
    pinMode(BLUE,OUTPUT);
    pinMode(B_1, INPUT_PULLUP);
    pinMode(B_2, INPUT_PULLUP);

    
    attachInterrupt(digitalPinToInterrupt(B_1), red_flash, FALLING); //ISR for button 1
    attachInterrupt(digitalPinToInterrupt(B_2), blue_flash, FALLING); //ISR for button 2
}

void loop()
{   

  
    digitalWrite(RED, HIGH); //task a, all three LEDs on
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
    
    if (flag==1){ //task b, if button 1 is pressed, flash red LED 3 times per second 
                  //and turn other LEDs off 
     digitalWrite(RED, HIGH);
     digitalWrite(BLUE, LOW);
     digitalWrite(GREEN, LOW);
     delay(20);
     digitalWrite(RED, LOW);
     delay(313);  
    }
   if (flag==2){  //task c, if button 2 is pressed, flash blue LED 2 times per second 
                  //and turn other LEDs off   
     digitalWrite(RED, LOW);
     digitalWrite(BLUE, HIGH);
     digitalWrite(GREEN, LOW);
     delay(20);
     digitalWrite(BLUE, LOW);
     delay(480);
   }
  if (flag==3){   //task d, if button 1 is pressed, flash green LED 1 times per second 
                  //and turn other LEDs off
     digitalWrite(RED, LOW);
     digitalWrite(BLUE, LOW);
     digitalWrite(GREEN, HIGH);
     delay(20);
     digitalWrite(GREEN, LOW);
     delay(980);
  }
}

void red_flash(){ //ISR for button 1 (flag=1) or button 1 and 2 (flag=3) being pressed
  flag=1;
  if(digitalRead(B_1)==LOW && digitalRead(B_2)==LOW)
  flag=3;
}

void blue_flash(){ //ISR for button 2 (flag=2) or button 1 and 2 (flag=3) being pressed
  flag=2;
  if(digitalRead(B_1)==LOW && digitalRead(B_2)==LOW)
  flag=3;

    }
