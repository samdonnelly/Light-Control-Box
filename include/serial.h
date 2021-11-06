/*
 *
 *
 */

// Include libraries 
#include <stdint.h>  // for integers 

#ifndef SERIAL_H
#define SERIAL_H

// State Functions
void function_A0  (void);  // State 0: light sequence 1
void function_A1  (void);  // State 1: light sequence 2
void function_A2  (void);  // State 2: light sequence 3
void function_A3  (void);  // State 3: light sequence 4
void function_A4  (void);  // State 4: light sequence for multiple buttons pushed
void serial_input (void);  // State 5: serial programming

// Misc functions 
void info(void);
void serial_prompt (void);  // Prompt to user for further serial input 

// Serial data processing functions  
void button_assignment(uint8_t address);

#endif /* SERIAL_H */
