
#ifndef Mimic
#define Mimic


#include <Arduino.h>
#include <IRremote.hpp>  // Use Arduino-IRremote library (install via Arduino IDE Library Manager)

// Define pins (as per your setup)
extern const int IR_RECV_PIN = 36;  // IR receiver (e.g., TSOP1838)
extern const int IR_SEND_PIN = 32;  // IR LED (direct connect with resistor, or via transistor for better range)

extern byte button_Array[8] = {4,5,34,35,15,18,23,19};



// Global variables to store the last received IR data
extern decode_type_t Protocol[8] = {UNKNOWN};
extern uint32_t Address[8] = {0};
extern uint32_t Command[8] = {0};
extern uint32_t RawData[8] = {0};  // For raw/unknown protocols
extern uint32_t Bit[8] = {0};

extern int signalCount = 0;

extern bool lastButtonState[8] = {HIGH};          // previous state for each button
extern unsigned long lastDebounceTime[8] = {0};   // last time the button changed
extern const unsigned long debounceDelay = 40;    // 40 ms is usually good

bool is_The_Signal_Already_There(decode_type_t Prtcl, uint32_t Ad,uint32_t Cmd,uint32_t Rwdata,uint32_t Bt);

void mimic_Initialization();

void what_deployed_mimic_does_is();



#endif






