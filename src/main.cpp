// Serial command of an Arduino via serial terminal 

/*
 * Notes: 
 * - An EEPROM write takes 3.3ms. EEPROM memory life is ~100000 write/erase cycles. 
 * - EEPROM locations that have never been written to have a value of 255
 * - Take all the inputs and assign them to one variables (use bit shifting) and 
 *   use that one variables in the main state machine. 
 */

/* 
 * ---------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------
 */   
#include <math.h>
#include <Arduino.h>
#include <EEPROM.h>  // For setting EEPROMs over serial (no need for flashing)

#include "main.h"
#include "serial.h"
#include "christmas_functions.h"
#include "halloween_functions.h"


/* 
 * ---------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------
 */

// For choosing state 
uint8_t serial_status;
uint8_t main_state;
uint8_t user_input;
uint8_t user_command;
uint8_t user_state;
boolean input_change;

// Universal counter for light sequence step through 
unsigned long counter;


/* 
 * ---------------------------------------------------------------------------------------------
 * Main State Machine 
 * ---------------------------------------------------------------------------------------------
 */
typedef const struct {
  void (*state_func)(void);            // Points to state function
  uint8_t state_delay;                 // Delay time
  uint8_t next_state[NUM_TRANS_MAIN];  // Next state to go to
} main_struct;


// Main State Machine 
main_struct MSM[NUM_STATES_MAIN] = {
  {&function_A0,  DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}},
  {&function_A1,  DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}},
  {&function_A2,  DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}},
  {&function_A3,  DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}},
  {&function_A4,  DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}},
  {&serial_input, DELAY_B, {button0_state, button1_state, button2_state, button3_state, 
    button4_state, program_state}}
};

/* 
 * ---------------------------------------------------------------------------------------------
 * Light Sequence State Machine 
 * ---------------------------------------------------------------------------------------------
 */
typedef const struct {
  void (*light_func)(void);
  uint8_t light_delay;
} light_struct;

light_struct LSM[NUM_STATES_LIGHTS] = {
  {&function_B0, DELAY_L},
  {&function_B1, DELAY_L},
  {&function_B2, DELAY_L},
  {&function_B3, DELAY_L},
  {&function_B4, DELAY_L},
  {&function_B5, DELAY_L},
  {&function_B6, DELAY_L},
  {&function_B7, DELAY_L},
  {&function_B8, DELAY_L},
  {&function_B9, DELAY_L},
  {&function_C0, DELAY_L},
  {&function_C1, DELAY_L},
  {&function_C2, DELAY_L},
  {&function_C3, DELAY_L},
  {&function_C4, DELAY_L},
  {&function_C5, DELAY_L},
  {&function_C6, DELAY_L},
  {&function_C7, DELAY_L},
  {&function_C8, DELAY_L},
  {&function_C9, DELAY_L}
};


/* 
 * ---------------------------------------------------------------------------------------------
 * Main Code
 * ---------------------------------------------------------------------------------------------
 */
void setup() {
  // System Parameters 
  Serial.begin(BAUD);
  // Serial.setTimeout(TIME);

  // Configure pins 
  pinMode(button0_pin,  INPUT);   // Button 0
  pinMode(button1_pin,  INPUT);   // Button 1
  pinMode(button2_pin,  INPUT);   // Button 2
  pinMode(button3_pin,  INPUT);   // Button 3
  pinMode(lightstring0, OUTPUT);  // Light String 0
  pinMode(lightstring1, OUTPUT);  // Light String 1
  pinMode(lightstring2, OUTPUT);  // Light String 2
  pinMode(lightstring3, OUTPUT);  // Light String 3

  // Begin interface
  info();
  delay(100);
  serial_prompt();
  main_state = button0_state;
  user_command = 0;
  input_change = 1;
  counter = 0;
}

// Continuous loop 
void loop() {
  user_input = (digitalRead(button3_pin) << 3) | (digitalRead(button2_pin) << 2) |
               (digitalRead(button1_pin) << 1) |  digitalRead(button0_pin);
  
  if ((user_input > 0) && input_change) {
    // Clear current light status 
    analogWrite(lightstring0, 0);
    analogWrite(lightstring1, 0);
    analogWrite(lightstring2, 0);
    analogWrite(lightstring3, 0);
    
    switch(user_input) {
      case 1:
        user_command = 0;
        break;
      case 2:
        user_command = 1;
        break;
      case 4:
        user_command = 2;
        break;
      case 8:
        user_command = 3;
        break;
      default:  // input_change prevents this state from being easily accessible
        user_command = 4;
        break;
    }
    input_change = 0;
  }
  
  if ((user_input == 0) && !input_change) {
    input_change = 1;
  }
  
  serial_status = (Serial.available() > 0) ? 1:0;
  user_command  = (serial_status << 3) | (user_command & 7);
  user_state    = (user_command >= 8) ? 5:user_command;

  main_state = MSM[main_state].next_state[user_state];

  (MSM[main_state].state_func)();
  delay(MSM[main_state].state_delay);
}

// State 0: Button 0 - Light Sequence 0
void function_A0(void) {
  (LSM[EEPROM.read(EEPROM0)].light_func)();
  delay(LSM[EEPROM.read(EEPROM0)].light_delay);
}

// State 1: Button 1 - Light Sequence 1
void function_A1(void) {
  (LSM[EEPROM.read(EEPROM1)].light_func)();
  delay(LSM[EEPROM.read(EEPROM1)].light_delay);
}

// State 2: Button 2 - Light Sequence 2
void function_A2(void) {
  (LSM[EEPROM.read(EEPROM2)].light_func)();
  delay(LSM[EEPROM.read(EEPROM2)].light_delay);
}

// State 3: Button 3 - Light Sequence 3
void function_A3(void) {
  (LSM[EEPROM.read(EEPROM3)].light_func)();
  delay(LSM[EEPROM.read(EEPROM3)].light_delay);
}

// State 4: Multiple buttons pressed - Light Sequence 4
void function_A4(void) {
  (LSM[EEPROM.read(EEPROM4)].light_func)();
  delay(LSM[EEPROM.read(EEPROM4)].light_delay);
}
