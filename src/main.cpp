#include <Monkey.h>

Monkey eyesLR(A0, 12, 11, 10, 1740, 2920, 100); // move with pwm = 30
Monkey eyesUD(A1, 7, 8, 9, 1250, 2100, 98); // move with pwm = 40
Monkey brows(A2, 13 ,2 ,3 , 1800, 2500, 70); // move with pwm = 60
Monkey lids(A3, 4, 5, 6, 800, 1800, 100); // move with pwm = 90
Monkey headLR(A0, 13, 2, 3,1100 ,3200 ,100);
Monkey headtilt(A1, 4, 5, 6,1800 ,3200 ,100);
Monkey mouth(A2, 7, 8, 9,1300 ,2300 ,80);
Monkey nose(A3, 11, 12, 10, 0, 0, 1);


//hello

void setup() {  
  Serial.begin(9600);
  //pinMode(0, INPUT); // for nose button
}
void loop() {
/*
headLR.moveto(0,120);
delay(200);
headLR.moveto(100,120);
delay(200);
headtilt.moveto(0,100);
delay(200);
headtilt.moveto(100,100);
delay(200);
mouth.moveto(0,100);
delay(200);
mouth.moveto(100,100);
delay(200);
nose.movespecific(100,0,50);
delay(100);
nose.movespecific(100,1,50);


eyesLR.moveto(0, 60);
delay(200);
eyesLR.moveto(100, 60);
delay(200);
eyesUD.moveto(0,40);
delay(200);
eyesUD.moveto(100,40);
delay(200);
lids.moveto(100,120);
delay(200);
lids.moveto(0,120);
delay(200);
brows.moveto(0,60);
delay(200);
brows.moveto(100,60);
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

int LRgoal = map(analogRead(A3), 0, 4095, 0, 100);

headLR.moveto(LRgoal, 120);

int tiltgoal = map(analogRead(A4), 0, 4095, 0, 100);

headtilt.moveto(tiltgoal, 53);

int mouthgoal = map(analogRead(A5), 0, 4095, 0, 100);

mouth.moveto(mouthgoal, 80);
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