/*
 * Functions that define christmas themed light sequences
 *
 */

/* 
 * ---------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------
 */
#include "christmas_functions.h"
#include "main.h"

#include <math.h>
#include <Arduino.h>

/* 
 * ---------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------
 */
uint8_t PWM_val_0A;
uint8_t PWM_val_0B;
uint8_t PWM_val_1;
uint8_t PWM_val_2;
uint8_t PWM_val_3A;
uint8_t PWM_val_3B;

// Function B0 
double T1W = 0.3*T_B0; // Oscillation period of each light string. Must be >= 0.25*T1.

// Caculation variables 
extern unsigned long counter;


/* 
 * ---------------------------------------------------------------------------------------------
 * Functions
 * ---------------------------------------------------------------------------------------------
 */

// Function B0 - Single File Fade
void function_B0(void) {
  
  if (counter < (-T_B0+4*T1W)/8) {
    PWM_val_0A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((1*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    PWM_val_3B = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((-1*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring0, PWM_val_0A);
    analogWrite(lightstring3, PWM_val_3B);
  }
  else if (counter < (3*T_B0-4*T1W)/8) {
    PWM_val_0A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((1*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring0, PWM_val_0A);
  }
  else if (counter < (T_B0+4*T1W)/8) {
    PWM_val_0A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((1*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    PWM_val_1  = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((3*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring1, PWM_val_1);
    analogWrite(lightstring0, PWM_val_0A);
  }
  else if (counter < (5*T_B0-4*T1W)/8) {
    PWM_val_1 = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((3*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring1, PWM_val_1);
  }
  else if (counter < (3*T_B0+4*T1W)/8) {
    PWM_val_1 = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((3*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    PWM_val_2 = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((5*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring1, PWM_val_1);
    analogWrite(lightstring2, PWM_val_2);
  }
  else if (counter < (7*T_B0-4*T1W)/8) {
    PWM_val_2 = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((5*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring2, PWM_val_2);
  } 
  else if (counter < (5*T_B0+4*T1W)/8) {
    PWM_val_2  = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((5*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    PWM_val_3A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((7*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring2, PWM_val_2);
    analogWrite(lightstring3, PWM_val_3A);
  }
  else if (counter < (9*T_B0-4*T1W)/8) {
    PWM_val_3A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((7*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring3, PWM_val_3A);
  }
  else if (counter < T_B0) {
    PWM_val_3A = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((7*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    PWM_val_0B = round(127.5*sin((2*M_PI/T1W)*counter - (2*M_PI*((9*T_B0-4*T1W)/(8*T1W)) + 
      90*M_PI/180)) + 127.5);
    analogWrite(lightstring3, PWM_val_3A);
    analogWrite(lightstring0, PWM_val_0B);
  }
  else {
    counter = 0;
    return;
  }
  counter++;
}

void function_B1(void) {
  // Function B1
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 0);
  analogWrite(lightstring3, 0);
}

void function_B2(void) {
  // Function B2
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 0);
}

void function_B3(void) {
  // Function B3
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 0);
  analogWrite(lightstring3, 255);
}

void function_B4(void) {
  // Function B4
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 0);
  analogWrite(lightstring3, 0);
}

void function_B5(void) {
  // Function B5
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 0);
}

void function_B6(void) {
  // Function B6
  analogWrite(lightstring0, 255);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 0);
  analogWrite(lightstring3, 255);
}

void function_B7(void) {
  // Function B7
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 0);
}

void function_B8(void) {
  // Function B8
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 255);
  analogWrite(lightstring2, 0);
  analogWrite(lightstring3, 255);
}

void function_B9(void) {
  // Function B9
  analogWrite(lightstring0, 0);
  analogWrite(lightstring1, 0);
  analogWrite(lightstring2, 255);
  analogWrite(lightstring3, 255);
}
