#include "Arduino.h"
#include "Monkey.h"
Monkey::Monkey(byte potentiometer_pin, int dir_pin1, int dir_pin2, int pwm_pin, int min_Ain, int max_Ain, int tolerance) {
	_potentiometer_pin = potentiometer_pin;
    _dir_pin1 = dir_pin1;
    _dir_pin2 = dir_pin2;
    _pwm_pin = pwm_pin;
    _min_Ain = min_Ain;
    _max_Ain = max_Ain;
    _tolerance = tolerance; // constructor assigns private variables to args

    pinMode(potentiometer_pin, INPUT);
    pinMode(dir_pin1, OUTPUT);
    pinMode(dir_pin2, OUTPUT);
    pinMode(pwm_pin, OUTPUT); // set all pinmodes
} // constructor now complete
/*
void Monkey::moveto(int pos, int pwm){// pos will be 0 to 100
    int pot_now = analogRead(_potentiometer_pin); //find current pot value
    int goal = map(pos, 0, 100, _min_Ain, _max_Ain); // work out intended pot value
    int error = goal - pot_now;
    Serial.println("beginning move");
    Serial.print("Goal:             ");
    Serial.println(goal);
    Serial.print("Pot now:         ");
    Serial.println(pot_now);
    Serial.print("Tolerance:        ");
    Serial.println(_tolerance);
    
    if (abs(error) > _tolerance){ // only power motor when magnitude of error exceeds tolerance
        if(pot_now < goal){ // this if/else statement sets direction
            digitalWrite(_dir_pin1, LOW);
            digitalWrite(_dir_pin2, HIGH);
            while (pot_now < goal){

                pot_now = analogRead(_potentiometer_pin);
                double closeness = fabs(pot_now - goal) / (_max_Ain - _min_Ain);
                Serial.print("ERROR:             ");
                Serial.println(abs(pot_now - goal));


                if(closeness > 0.4){
                    pot_now = analogRead(_potentiometer_pin);
                    analogWrite(_pwm_pin, pwm);
                    Serial.println("normal loop A");
                    Serial.print("Potnow:");
                    Serial.print(pot_now);
                    Serial.print(" Goal:");
                    Serial.println(goal);
                }
                else{
                    Serial.print("else loop         -           ");
                    Serial.println(closeness);
                    analogWrite(_pwm_pin, pwm);
                    delay(9);            
                    analogWrite(_pwm_pin,0);
                    delay(1);
                }
            }
            analogWrite(_pwm_pin, 0); // once close enough turn off PWM
        } 
        else{
            digitalWrite(_dir_pin1, HIGH);
            digitalWrite(_dir_pin2, LOW);

            while (pot_now > goal){

                Serial.print("ERROR:             ");
                Serial.println(abs(pot_now - goal));

                pot_now = analogRead(_potentiometer_pin);
                double closeness = fabs(pot_now - goal)/(_max_Ain-_min_Ain);
                //Serial.println(closeness);

                if(closeness > 0.4){
                    pot_now = analogRead(_potentiometer_pin);
                    analogWrite(_pwm_pin, pwm);
                    Serial.println("normal loop B");
                    Serial.print("Potnow:");
                    Serial.print(pot_now);
                    Serial.print(" Goal:");
                    Serial.println(goal);
                }
                else{
                    Serial.print("else loop         -           ");
                    Serial.println(closeness);
                    analogWrite(_pwm_pin, pwm);
                    delay(9);            
                    analogWrite(_pwm_pin,0);
                    delay(1);
                }
                }
            analogWrite(_pwm_pin, 0);
        }
    }
    else{
        Serial.println("DONE DONE DONE DONE DONE");
    }
} */

void Monkey::moveto(int pos, int pwm){// pos will be 0 to 100
    int pot_now = analogRead(_potentiometer_pin); //find current pot value
    int goal = map(pos, 0, 100, _min_Ain, _max_Ain); // work out intended pot value
    int error = goal - pot_now;
    int range = _max_Ain - _min_Ain;
    /*
    Serial.println("beginning move");
    Serial.print("Goal:             ");
    Serial.println(goal);
    Serial.print("Pot now:         ");
    Serial.println(pot_now);
    Serial.print("Tolerance:        ");
    Serial.println(_tolerance);
    */
    if (abs(error) > _tolerance)// only power motor when magnitude of error exceeds tolerance      
    { 
        Monkey::goindirection(pot_now, goal, pwm);
        pot_now = analogRead(_potentiometer_pin);
        error = goal - pot_now;
        Serial.println(error);                                           
        if (abs(error) < (_tolerance * 3)) // slow down when within N tolerances
        { 
            Serial.println("Fine tuning");
            analogWrite(_pwm_pin, pwm*0.8);            
            delayMicroseconds(120);                        
            analogWrite(_pwm_pin,0);
            delayMicroseconds(40);                    
        }        
        
    }
    else
    {
        Serial.println("Within Tolerance");
        analogWrite(_pwm_pin, 0);
    }
    //analogWrite(_pwm_pin, 0);
     // if error is not larger than tolerance ensure PWM is off
}

void Monkey::goindirection(int pot_now, int goal, int pwm)
{
    if(pot_now < goal)
        {
            digitalWrite(_dir_pin1, LOW);
            digitalWrite(_dir_pin2, HIGH);
            analogWrite(_pwm_pin, pwm);   
        }else{
            digitalWrite(_dir_pin1, HIGH);
            digitalWrite(_dir_pin2, LOW);
            analogWrite(_pwm_pin, pwm);
        }
}

void Monkey::printvalue(void)
{
    int pot_now = analogRead(_potentiometer_pin);
    Serial.println(pot_now);
}

void Monkey::movespecific(int ms, bool dir, int pwm){
    if (dir == true){
        digitalWrite(_dir_pin1, HIGH);
        digitalWrite(_dir_pin2, LOW);
        analogWrite(_pwm_pin, pwm);
        delay(ms);
        analogWrite(_pwm_pin, 0);
    }
    else{
        digitalWrite(_dir_pin2, HIGH);
        digitalWrite(_dir_pin1, LOW);
        analogWrite(_pwm_pin, pwm);
        delay(ms);
        analogWrite(_pwm_pin, 0);
    }
}
/*
void Monkey::calibrate(void){
    int minR = 2048;
    int maxR = 2048;
    // need to create a function which actuates fully in both directions and 
    // records the maximum and minimum values then automatically sets 
    // limits to measured values
    }
*/
