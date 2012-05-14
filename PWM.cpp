#include "PWM.h"

/* <<constructor>> DEFAULTS WITHOUT PIN */
PWM::PWM(void) {
	/* by setting the pin to 0 we make sure you can't turn anything on or off until the pin is set */
	_pin = 0;
	/* 255 is the full PWM setting for analogWrite */
  _pwm = 255;
  /* expect full PWM range */
  _max = 255;
  /* some things may not work at very low voltages, so we set a min to fix that */
  _min = 1;
  /* our way to track if the PWM channel is on or off */
  _state = LOW;
  /* we don't know the pin yet, so we'll set it to OUTPUT when the pin is set.
     but we can make sure the status LED pin is set */
  pinMode(STATUS, OUTPUT);
}

/* <<constructor>> DEFAULTS WITH PIN */
PWM::PWM(byte pin) {
	/* we know the pin, so lets set it and make sure it set to OUTPUT */
	_pin = pin;
  pinMode(_pin, OUTPUT);
  /* let's make sure the status LED pin is set */
  pinMode(STATUS, OUTPUT);
  /* 255 is the full PWM setting for analogWrite */
  _pwm = 255;
  /* expect full PWM range */
  _max = 255;
  /* some things may not work at very low voltages, so we set a min to fix that */
  _min = 1;
  /* a few ways to track if the PWM channel is on or off */
  _state = LOW; STATE = LOW;
}

/* MIGHT NEED THIS */
PWM::~PWM() {
  /*nothing to destruct*/
}

/* SET THE PIN */
void PWM::setPin(byte pin) {
	_pin = pin;
	pinMode(pin, OUTPUT);
}

/* SET THE MAX VOLTAGE */
void PWM::setMax(byte max) {
  _max = max;
}

/* SET THE MIN VOLTAGE */
void PWM::setMin(byte min) {
  _min = min;
}

/* SET THE PWM */
/* PLEASE NOTE!!! JUST BECAUSE YOU SET IT DOESN'T MEAN IT'S ON!!!  */
void PWM::setPWM(byte val) {
	/* constrain the PWM to the min and max values */
	byte PWM = constrain(map(val,1,255, _min, _max),_min,_max);
	/* set the PWM */
  _pwm = PWM;
}

/* RETURN THE CURRENT STATE */
boolean PWM::getState() {
	STATE = _state;
	return _state;
}

/* RETURN THE MIN PWM */
byte PWM::getMin() {
  return _min;
}

/* RETURN THE MAX PWM */
byte PWM::getMax() {
  return _max;
}


/* TURN ON THE PWM CHANNEL */
void PWM::on() {
	/* is the pin set?  */
	if( _pin == 0 ) { 
		return;
	}
	/* if the PWM is set to 0 then set it to the max PWM */
	if ( _pwm == 0 ) {
		_pwm = _max;
	}
	/* set the state to HIGH */
	_state = HIGH; STATE = HIGH;
	/* write the PWM to the pin */
  analogWrite(_pin, _pwm);
}

/* TURN OFF THE PWM CHANNEL */
void PWM::off() {
	/* is the pin set?  */
	if( _pin == 0 ) {
		return;
	}
	/* set the state to LOW */
	_state = LOW; STATE = LOW;
	/* turn the PWM channel off */
  analogWrite(_pin, 0);
}

/* TOGGLE THE PWM CHANNEL */
void PWM::toggle() {
	/* if the channel is off */
	if( _state == LOW ) {
		/* turn it on */
		on();
	} else {
		/* otherwise turn it off */
		off();
	}
}

CONTROL::CONTROL() {
  A.setPin(CHANNEL_A); B.setPin(CHANNEL_B); C.setPin(CHANNEL_C);
  D.setPin(CHANNEL_D); E.setPin(CHANNEL_E); F.setPin(CHANNEL_F);
}

CONTROL::~CONTROL() {
  /*nothing to destruct*/
}

void CONTROL::all_off() {
  A.off(); B.off(); C.off(); D.off(); E.off(); F.off();
}

void CONTROL::all_on() {
  A.on(); B.on(); C.on(); D.on(); E.on(); F.on();
}

void CONTROL::setMax_all(byte max_value) {
  A.setMax(max_value); B.setMax(max_value); C.setMax(max_value);
  D.setMax(max_value); E.setMax(max_value); F.setMax(max_value);
  
}

void CONTROL::setMin_all(byte min_value) {
  A.setMin(min_value); B.setMin(min_value); C.setMin(min_value);
  D.setMin(min_value); E.setMin(min_value); F.setMin(min_value);
}

void CONTROL::setPWM_all(byte PWM_value) {
  A.setPWM(PWM_value); B.setPWM(PWM_value); C.setPWM(PWM_value);
  D.setPWM(PWM_value); E.setPWM(PWM_value); F.setPWM(PWM_value);
}

void CONTROL::random_pwm() {
  /* get a random pwm for each channel using it's min and max pwm values */
  byte pwm_A = random(A.getMin(), A.getMax()),
       pwm_B = random(B.getMin(), B.getMax()),
       pwm_C = random(C.getMin(), C.getMax()),
       pwm_D = random(D.getMin(), D.getMax()),
       pwm_E = random(E.getMin(), E.getMax()),
       pwm_F = random(F.getMin(), F.getMax());
  
  A.setPWM(pwm_A); B.setPWM(pwm_B); C.setPWM(pwm_C); 
  D.setPWM(pwm_D); E.setPWM(pwm_E); F.setPWM(pwm_F);
}


/* CONTROL class functions */
void CONTROL::random_on() {
  boolean on_off_A = random(2), on_off_B = random(2), on_off_C = random(2),
          on_off_D = random(2), on_off_E = random(2), on_off_F = random(2);
  
  if ( on_off_A == 1) { 
    A.on();
  } else {
    A.off();
  }
  if ( on_off_B == 1) { 
    B.on();
  } else {
    B.off();
  }
  if ( on_off_C == 1) { 
    C.on();
  } else {
    C.off();
  }
  if ( on_off_D == 1) { 
    D.on();
  } else {
    D.off();
  }
  if ( on_off_E == 1) { 
    E.on();
  } else {
    E.off();
  }
  if ( on_off_F == 1) { 
    F.on();
  } else {
    F.off();
  }
}

void CONTROL::random_memory_reset() {
	for ( byte i = 0; i < 6; i++ ) {
		random_memory[i] == LOW;
	}
}

void CONTROL::random_memory_set() {
	for ( byte i = 0; i < 6; i++ ) {
		boolean this_chan = random(2);
		random_memory[i] = this_chan;
  }
}

void CONTROL::random_memory_on() {
	if ( random_memory[0] == 1) { 
    A.on();
  } else {
    A.off();
  }
  if ( random_memory[1] == 1) { 
    B.on();
  } else {
    B.off();
  }
  if ( random_memory[2] == 1) { 
    C.on();
  } else {
    C.off();
  }
  if ( random_memory[3] == 1) { 
    D.on();
  } else {
    D.off();
  }
  if ( random_memory[4] == 1) { 
    E.on();
  } else {
    E.off();
  }
  if ( random_memory[5] == 1) { 
    F.on();
  } else {
    F.off();
  }
}