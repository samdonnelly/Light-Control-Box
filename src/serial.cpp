/*
 * Functions that define christmas themed light sequences
 *
 */

/* 
 * ---------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------
 */
#include "serial.h"
#include "main.h"
#include "christmas_functions.h"
#include "halloween_functions.h"

#include <Arduino.h>
#include <EEPROM.h>  // For setting EEPROMs over serial (no need for flashing)


/* 
 * ---------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------
 */

// Used to store serial input data 
char        buf[BUF_SIZE];
char       *ID_buf_pointer;
uint8_t     ID_buf_int;
char       *data_buf_pointer;
short int   data_buf_int;

// Lookup table of light sequence addresses 
uint8_t light_sequence[NUM_STATES_LIGHTS][2] = {
  {176,  0}, // Function B0
  {177,  1}, // Function B1
  {178,  2}, // Function B2
  {179,  3}, // Function B3
  {180,  4}, // Function B4
  {181,  5}, // Function B5
  {182,  6}, // Function B6
  {183,  7}, // Function B7
  {184,  8}, // Function B8
  {185,  9}, // Function B9
  {192, 10}, // Function C0
  {193, 11}, // Function C1
  {194, 12}, // Function C2
  {195, 13}, // Function C3
  {196, 14}, // Function C4
  {197, 15}, // Function C5
  {198, 16}, // Function C6
  {199, 17}, // Function C7
  {200, 18}, // Function C8
  {201, 19}  // Function C9
};


/* 
 * ---------------------------------------------------------------------------------------------
 * Functions
 * ---------------------------------------------------------------------------------------------
 */

// Main state machine - state 4: serialpProgramming
void serial_input(void) {
  // Process Serial.read() data
  for (int counter = 0; Serial.available() > 0; counter++) {
    buf[counter] = Serial.read();
    delay(2);
  }
  
  // Parse Data 
  ID_buf_pointer   = strtok(buf, " ");
  data_buf_pointer = strtok(NULL, " ");
  ID_buf_int   = (unsigned long)strtol(ID_buf_pointer, NULL, 0);
  data_buf_int = (unsigned long)strtol(data_buf_pointer, NULL, 0);
  
  // Assign a light function to an EEPROM
  switch (ID_buf_int) {
    case 160: // Address 0xA0
      button_assignment(EEPROM0);
      Serial.print("EEPROM0 = ");
      Serial.println(EEPROM.read(EEPROM0));
      break;
    case 161: // Address 0xA1
      button_assignment(EEPROM1);
      Serial.print("EEPROM1 = ");
      Serial.println(EEPROM.read(EEPROM1));
      break;
    case 162: // Address 0xA2
      button_assignment(EEPROM2);
      Serial.print("EEPROM2 = ");
      Serial.println(EEPROM.read(EEPROM2));
      break;
    case 163: // Address 0xA3
      button_assignment(EEPROM3);
      Serial.print("EEPROM3 = ");
      Serial.println(EEPROM.read(EEPROM3));
      break; 
    case 164: // Address 0xA4
      button_assignment(EEPROM4);
      Serial.print("EEPROM4 = ");
      Serial.println(EEPROM.read(EEPROM4));
  }
  
  memset(buf, 0, sizeof(buf));
  serial_prompt();
}

// Match an address input over serial to a light sequence
void button_assignment(uint8_t address) {
  for (uint8_t i = 0; i < (sizeof(light_sequence)/sizeof(light_sequence[0])); i++) {
    if (data_buf_int == light_sequence[i][0]) {
      EEPROM.update(address, light_sequence[i][1]);
      break;
    }
  }
}

// Serial Prompt
void serial_prompt(void) {
  Serial.print(">>> ");
}

// Provides info for the user to set EEPROMs over serial using the serial terminal.
void info(void) { 
  Serial.println();
  Serial.println("Refer to data sheet for address and data formats");
  Serial.println();
}
