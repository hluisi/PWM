#ifndef PWM_H
#define PWM_H
 
#include <Arduino.h> 

#define CHANNEL_A  3
#define CHANNEL_B  5
#define CHANNEL_C  6
#define CHANNEL_D  9
#define CHANNEL_E 10
#define CHANNEL_F 11
#define STATUS    13


class PWM {
  public:
  	
  	boolean STATE;
  	PWM(void);
    PWM(byte pin);
    ~PWM();
    void setPin(byte pin);
    void setMax(byte max);
    void setMin(byte min);
    void setPWM(byte val);
    boolean getState();
    byte getMin();
    byte getMax();
    void on();
    void off();
    void toggle();
    
  private:
  	byte _pin;
  	byte _pwm;
  	byte _max;
  	byte _min;
  	boolean _state;
};


class CONTROL {
	private:
		boolean random_memory[6];
		
  public:
    PWM A, B, C, D, E, F;
    CONTROL(void);
    ~CONTROL();
    void all_off();
    void all_on();
    void setMax_all(byte max_value);
    void setMin_all(byte min_value);
    void setPWM_all(byte PWM_value);
    void random_pwm();
    void random_on();
    void total_randomness();
    void random_memory_reset();
    void random_memory_set();
    void random_memory_on();
};


#endif