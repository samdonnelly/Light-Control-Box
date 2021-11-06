/*
 *
 *
 */

// Include libraries 
// #include <stdint.h>  // for integers 
// #include <Arduino.h>

#ifndef MAIN_H
#define MAIN_H

// Setup constants
#define BAUD     115200  // Baud rate of 9600 bps 
#define TIME     2       // Serial timeout time 
#define BUF_SIZE 64      // Adruino Serial.available buf size if 64 bytes

// Pin assignments
#define button0_pin  2   // Button 0: Pin 2
#define button1_pin  4   // Button 1: Pin 4
#define button2_pin  7   // Button 2: Pin 7
#define button3_pin  8   // Button 3: Pin 8
#define lightstring0 6   // Light Sequence 0: Pin 6
#define lightstring1 9   // Light Sequence 1: Pin 9
#define lightstring2 10  // Light Sequence 2: Pin 10
#define lightstring3 11  // Light Sequence 3: Pin 11

// EEPROM Addresses
#define EEPROM0 0  // EEPROM address 1
#define EEPROM1 1  // EEPROM address 2
#define EEPROM2 2  // EEPROM address 3
#define EEPROM3 3  // EEPROM address 4
#define EEPROM4 4  // EEPROM address 5 

// State machine sizes 
#define NUM_TRANS_MAIN    6   // Number of transitions in main state machine 
#define NUM_STATES_MAIN   6   // Number of states in main state machine 
#define NUM_STATES_LIGHTS 20  // Number of states in light sequence state machine 

// Main state machine states 
#define button0_state 0
#define button1_state 1
#define button2_state 2
#define button3_state 3
#define button4_state 4
#define program_state 5

// Delays 
#define DELAY_B 0  // Delay for switching between button states 
#define DELAY_L 0  // Delay after each light sequence state iteration 

// Function B0
#define T_B0 85000  // Oscillation period of the combined light sequence. Make an adjustable EEPROM.

// Function C0
#define T_C0   500000
#define T_C0_W 1000
#define T_C0_F 750

#endif /* MAIN_FUNCTIONS_H */


