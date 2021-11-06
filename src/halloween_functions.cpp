/*
 * Functions that define halloween themed light sequences
 *
 */

/* 
 * ---------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------
 */
#include "halloween_functions.h"
#include "main.h"

#include <math.h>
#include <Arduino.h>

/* 
 * ---------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------
 */
uint8_t PWM_val;

extern unsigned long counter;

/* 
 * ---------------------------------------------------------------------------------------------
 * Functions 
 * ---------------------------------------------------------------------------------------------
 */

// Function C0: Darth Vader Light Saber Sequence
void function_C0(void) {
  if (counter < T_C0*0.1) {
    analogWrite(lightstring0, 0);
    analogWrite(lightstring1, 0);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0*0.1 + 1*T_C0_F) {
    analogWrite(lightstring0, 255);
    analogWrite(lightstring1, 0);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0*0.1 + 2*T_C0_F) {
    analogWrite(lightstring0, 255);
    analogWrite(lightstring1, 255);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0*0.1 + 3*T_C0_F) {
    analogWrite(lightstring0, 255);
    analogWrite(lightstring1, 255);
    analogWrite(lightstring2, 255);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0*0.1 + 4*T_C0_F) {
    analogWrite(lightstring0, 255);
    analogWrite(lightstring1, 255);
    analogWrite(lightstring2, 255);
    analogWrite(lightstring3, 255);
  }
  else if (counter < T_C0*0.3) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.3 + 10*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 100);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.6) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.6 + 0.4*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, 0);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.6 + 0.8*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, 0);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.6 + 1.2*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0*0.6 + 1.6*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0 - 1.2*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, PWM_val);
  }
  else if (counter < T_C0 - 0.8*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, PWM_val);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0 - 0.4*T_C0_F) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, PWM_val);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
  }
  else if (counter < T_C0) {
    PWM_val = round(25*cos((2*M_PI/T_C0_W)*counter) + 230);
    analogWrite(lightstring0, PWM_val);
    analogWrite(lightstring1, 0);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
  }
  else {
    counter = 0;
    return;
  }
  counter++;
}

// Function C1
void function_C1(void) {
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 0); 
}

void function_C2(void) {
  // Function C2
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 255);
}

void function_C3(void) {
  // Function C3
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 255);
}

void function_C4(void) {
  // Function C4
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 255);
}

void function_C5(void) {
  // Function C5
  analogWrite(lightstring0, 50);
  analogWrite(lightstring1, 50);
  analogWrite(lightstring2, 50);
  analogWrite(lightstring3, 50);
}

void function_C6(void) {
  // Function C6
  analogWrite(lightstring0, 100);
  analogWrite(lightstring1, 100);
  analogWrite(lightstring2, 100);
  analogWrite(lightstring3, 100);
}

void function_C7(void) {
  // Function C7
  analogWrite(lightstring0, 150);
  analogWrite(lightstring1, 150);
  analogWrite(lightstring2, 150);
  analogWrite(lightstring3, 150);
}

void function_C8(void) {
  // Function C8
  analogWrite(lightstring0, 200);
  analogWrite(lightstring1, 200);
  analogWrite(lightstring2, 200);
  analogWrite(lightstring3, 200);
}

void function_C9(void) {
  // Function C9
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 188);
  analogWrite(lightstring2, 125);
  analogWrite(lightstring3, 63);
}


