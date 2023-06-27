#ifndef Monkey_h
#define Monkey_h
#include "Arduino.h" 
class Monkey {
public:
	Monkey(byte potentiometer_pin, int dir_pin1, int dir_pin2, int pwm_pin, int min_Ain, int max_Ain, int tolerance);
	void moveto(int pos, int pwm); // pos will be between 0 and 100,
    void printvalue(void);
    void movespecific(int ms, bool dir, int pwm);
    void goindirection(int pot_now, int goal, int pwm);    
    // pwm will be the duty cycle out of 255 (should be max 105 for safety)
private:
    byte _potentiometer_pin; // byte because we need a letter and a character
    int _dir_pin1; // Direction pins
    int _dir_pin2; // dictate H bridge transistors
    int _pwm_pin;  // PWM duty cycle out of 255
    int _min_Ain;  // Minimum and maximum potentiometer voltage values 
    int _max_Ain;  // (end of travel for mechanisms)
    int _tolerance;// acceptable error - prevents oscillation
};
#endif