#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad bleGamepad("Dragonfly","Mechanisium",90);


#define numOfButtons 10
#define touchButtonThreshold 1000

byte previousButtonStates[numOfButtons];
byte currentButtonStates[numOfButtons];
byte buttonPins[numOfButtons] = {4,5,35,34,18,15,23,19,14,27};
byte physicalButtons[numOfButtons] = {14,13,15,12,1,0,3,2,8,9};



boolean capacitiveRead(byte thisPin , uint16_t threshold)
{
  uint16_t val = touchRead(thisPin);
  if(val < threshold)
  {
    return LOW;
  }
  else
{
    return HIGH;
  }

}


void what_deployed_Dragonfly_does_is() {
  if (!bleGamepad.isConnected()) {
    return;  // No need to waste time if not connected
  }

  bool anyChange = false;

  // Read all buttons first
  for (byte i = 0; i < numOfButtons; i++) {
    if (buttonPins[i] == 14 || buttonPins[i] == 27) {
      // Capacitive touch pins
      currentButtonStates[i] = capacitiveRead(buttonPins[i], touchButtonThreshold);
    } else {
      // Normal digital pins
      currentButtonStates[i] = digitalRead(buttonPins[i]);
    }

    // Detect change
    if (currentButtonStates[i] != previousButtonStates[i]) {
      anyChange = true;

      if (currentButtonStates[i] == LOW) {  // Pressed
        bleGamepad.press(physicalButtons[i]);
        Serial.printf("Button %d pressed (physical %d)\n", i+1, physicalButtons[i]);
      } else {  // Released
        bleGamepad.release(physicalButtons[i]);
        Serial.printf("Button %d released (physical %d)\n", i+1, physicalButtons[i]);
      }
    }
  }

  // Only if something changed → update previous states & send report
  if (anyChange) {
    memcpy(previousButtonStates, currentButtonStates, sizeof(currentButtonStates));
    bleGamepad.sendReport();   // ← This is the most important missing line!
  }

  delay(5);  // Small delay — helps debounce + reduces CPU spam
}




  void dragonfly_Initialization()
  {
    for (byte currentPinIndex = 0; currentPinIndex < numOfButtons; currentPinIndex++)
    {
      if(buttonPins[currentPinIndex] == 34 || buttonPins[currentPinIndex] == 35 || buttonPins[currentPinIndex] == 15 ) 
      {
        pinMode(buttonPins[currentPinIndex], INPUT);
        previousButtonStates[currentPinIndex] = HIGH;
        currentButtonStates[currentPinIndex] = HIGH;
      }
      else
    {
        pinMode(buttonPins[currentPinIndex], INPUT_PULLUP);
        previousButtonStates[currentPinIndex] = HIGH;
        currentButtonStates[currentPinIndex] = HIGH;
      }
    }

    BleGamepadConfiguration personalConfig;
    personalConfig.setAutoReport(false);
    personalConfig.setWhichAxes(0,0,0,0,0,0,0,0);
    personalConfig.setButtonCount(numOfButtons);

    // Start BLE gamepad with default config (16 buttons, no axes needed) or a personal config like i did above
    bleGamepad.begin(&personalConfig);

    Serial.println("Dragonfly Initialized");

  }


  void setup() {
    Serial.begin(115200);
    dragonfly_Initialization();

    
  }

  void loop() {
    what_deployed_Dragonfly_does_is();
  }
