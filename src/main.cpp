#include <Arduino.h>
/**
 * @brief Initializations and defines
 * Used Pin 4 and 5 on Uno
 */
#define ledPinSlow 4
#define ledPinFast 5

uint16_t currentTime;
long ledSlowRate = 1000;
boolean ledSlowState = LOW;
long ledFastRate = 250;
boolean ledFastState = LOW;

/**
 * @brief Get Current starting time for each LED
 * Fast LED timestamp = previousTimeFast
 * Slow LED timestamp = previousTimeSlow
 */
unsigned long previousTimeSlow = millis();
unsigned long previousTimeFast = millis();

void setup()
{
  pinMode(ledPinSlow, OUTPUT);
  pinMode(ledPinFast, OUTPUT);
}


/**
 * @brief Entering the super loop structure.
 * Please refer to flowchart on project Readme.md
 */
void loop()
{
  currentTime = millis();

  if (currentTime - previousTimeSlow > ledSlowRate)
  {
    if (ledSlowState == LOW)
    {
      ledSlowState = HIGH;
      digitalWrite(ledPinSlow, ledSlowState);
    }
    else
    {
      ledSlowState = LOW;
      digitalWrite(ledPinSlow, ledSlowState); // redundant, only added in for completeness and readability
    }
    previousTimeSlow = currentTime;
  }

  if (currentTime - previousTimeFast > ledFastRate)
  {
    if (ledFastState == LOW)
    {
      ledFastState = HIGH;
      digitalWrite(ledPinFast, ledFastState);
    }
    else
    {
      ledFastState = LOW;
      digitalWrite(ledPinFast, ledFastState); // redundant, only added in for completeness and readability
    }
    previousTimeFast = currentTime;
  }
}