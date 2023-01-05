#define B_1 2
#define B_2 3
#define RED 8
#define GREEN 9
#define BLUE 10

void setup()
{
    pinMode(RED,OUTPUT);
    pinMode(GREEN,OUTPUT);
    pinMode(BLUE,OUTPUT);
    pinMode(B_1, INPUT_PULLUP);
    pinMode(B_2, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(B_1), red_flash, RISING);
    attachInterrupt(digitalPinToInterrupt(B_2), blue_flash, RISING);
    //attachInterrupt(digitalPinToInterrupt(B_1&&B_2), green_flash, LOW);
}

void loop()
{   
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
    
}

void red_flash () {
 while(digitalRead(B_1)!=FALLING&& digitalRead(B_2)!=FALLING){
 digitalWrite(RED, HIGH);
 digitalWrite(BLUE, LOW);
 digitalWrite(GREEN, LOW);
 delayMicroseconds(200);
 digitalWrite(RED, LOW);
 delayMicroseconds(3130); 
 }
 
}

void blue_flash (){
    while(digitalRead(B_1)!=FALLING&& digitalRead(B_2)!=FALLING){

 digitalWrite(RED, LOW);
 digitalWrite(BLUE, HIGH);
 digitalWrite(GREEN, LOW);
 delay(20);
 digitalWrite(BLUE, LOW);
 delay(480); 
    }
}

void green_flash (){
 digitalWrite(RED, LOW);
 digitalWrite(BLUE, LOW);
 digitalWrite(GREEN, HIGH);
 delay(20);
 digitalWrite(GREEN, LOW);
 delay(980); 
}
