#include <Monkey.h>

Monkey eyesLR(A0, 12, 11, 10, 1800, 2870, 100); // move with pwm = 30
Monkey eyesUD(A1, 7, 8, 9, 1350, 2100, 90); // move with pwm = 40
Monkey brows(A2, 4, 5, 6, 1800, 2500, 40); // move with pwm = 60
//Monkey lids(A3, 13 ,2 ,3, 800, 1800, 100); // move with pwm = 90
Monkey headLR(A0, 11, 12, 10, 1100, 3200, 100);
Monkey headUD(A1, 4, 5, 6, 1800, 2600, 100);
Monkey mouth(A2, 8, 7, 9, 1300, 2300, 40);
Monkey nose(A3, 13, 2, 3, 0, 0, 1);

void setup() {  
  Serial.begin(9600);
}
void loop() {
/*
Serial.println("begin");

Serial.println("HEAD LR");
headLR.moveto(0,80);
delay(200);
headLR.moveto(100,80);
delay(200);

Serial.println("HEAD UD");
headUD.moveto(0,80);
delay(200);
headUD.moveto(100,80);
delay(200);

Serial.println("MOUTH");
mouth.moveto(0,100);
delay(200);
mouth.moveto(100,100);
delay(200);

Serial.println("NOSE");
nose.movespecific(100,0,50);
delay(100);
nose.movespecific(100,1,50);
*/
Serial.println("Eyes LR");
eyesLR.moveto(0, 35);
delay(200);
eyesLR.moveto(100, 35);
delay(200);
Serial.println("Eyes UD");
eyesUD.moveto(0,30);
delay(200);
eyesUD.moveto(100,30);
delay(200);

/*
Serial.println("brows");
brows.moveto(0,100);
delay(200);
brows.moveto(100,100);
delay(200); 


lids.moveto(100,120);
delay(200);
lids.moveto(0,120);
delay(200);
eyesLR.moveto(50,60);
delay(200);
eyesUD.moveto(50,40);
delay(200);
lids.moveto(50,120);
delay(200);
brows.moveto(50,60);
delay(200);
*/


/*
int LRgoal = map(analogRead(A3), 0, 4095, 0, 100);

headLR.moveto(LRgoal, 150);

int tiltgoal = map(analogRead(A4), 0, 4095, 0, 100);

headtilt.moveto(tiltgoal, 90);

int mouthgoal = map(analogRead(A5), 0, 4095, 0, 100);
mouth.printvalue();
mouth.moveto(mouthgoal, 120);
*/
/*

bool nosebutton = digitalRead(0);
Serial.print(nosebutton);
if (nosebutton == true)
{
nose.movespecific(100,0,50);
delay(100);
nose.movespecific(100,1,50);
}
*/
/*
int browgoal = map(analogRead(A6), 0, 4095, 0, 100);

brows.moveto(browgoal, 45);

int LRgoal = map(analogRead(A4), 0, 4095, 0, 100);

eyesLR.moveto(LRgoal, 35);

int UDgoal = map(analogRead(A5), 0, 4095, 0, 100);

eyesUD.moveto(UDgoal, 45);
*/
}