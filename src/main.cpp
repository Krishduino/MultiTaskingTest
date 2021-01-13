#include <Arduino_FreeRTOS.h>
#include <Arduino.h>

static void meTask1(void* pvParameters);
static void meTask2(void* pvParameters);
static void meTask3(void* pvParameters);
static void idleTask(void* pvParameters);
/**
 * @brief Setup Fn so that pins and serial monitor are initialized.
 * Also creates tasks for scope of this project.
 */
void setup()
{
  Serial.begin(9600);
  Serial.println("Setup Initialized!");
  for (int i = 4; i < 8; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  /**
   * Task Creation 
   */
  xTaskCreate(meTask1, "Task1", 100, NULL, 1, NULL);
  xTaskCreate(meTask2, "Task2", 100, NULL, 2, NULL);
  xTaskCreate(meTask3, "Task3", 100, NULL, 3, NULL);
  xTaskCreate(idleTask, "Task0", 100, NULL, 0, NULL);
  
}

void loop()

{
}

static void meTask1(void* pvParameters)
{
  while(1)
  {
    digitalWrite(4,HIGH);
    Serial.println("In Task1");
    vTaskDelay(250/portTICK_PERIOD_MS);
    digitalWrite(4,LOW);
    vTaskDelay(250/portTICK_PERIOD_MS);
    Serial.println("LED off") ;
  }
}

static void meTask2(void* pvParameters)
{
  while(1)
  {
    digitalWrite(5,HIGH); 
    Serial.println("In Task2");
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(5, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

static void meTask3(void* pvParameters)
{
  while(1)
  {
    digitalWrite(6,HIGH);
    Serial.println("In Task3");
    vTaskDelay(1000/portTICK_PERIOD_MS); 
    digitalWrite(6, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

static void idleTask(void* pvParameters)
{
  while(1)
  {
    digitalWrite(7,HIGH);
    Serial.println("In Idle now");
    vTaskDelay(50/portTICK_PERIOD_MS); 
  }
}