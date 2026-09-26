// Creation of the sensor task, can task, and queue

#include "FreeRTOS.h"
#include "can.h"
#include "sensor.h"
#include "task.h"
#include "queue.h"

typedef struct{
    float signal; 
    bool err; 
} SensorData;

//Queue for passing data between tasks
QueueHandle_t queue; 

//Virtual sensor Task
void SensorTask(void *pvParameters){
    for(;;){
        float signal = generateSignal(); 
        float movingAverage = averageFilter(signal); 
        bool err = detectError(movingAverage); 

        SensorData data; 
        data.signal = movingAverage; 
        data.err = err; 
        
        //send the sensor data to the queue
        xQueueSend(queue, &data, portMAX_DELAY);

        //wait 100 ticks before sending another SensorData
        vTaskDelay(pdMS_TO_TICKS(100));
    }

}


//the task that assembles a frame from the sensordata in the queue and transmits it
void  CanTask(void *pvParameters){
    for(;;){
        SensorData data; 
        xQueueReceive(queue, &data, portMAX_DELAY);

        CanFrame frame = formatFrame(data.signal, data.err); 
        transmitFrame(frame);
    }
}



void main(){
    // create the queue holding max 5 sensorData items; 
    queue = xQueueCreate(5, sizeof(SensorData));
    
    //sensortask
    xTaskCreate(&SensorTask, "Sensor", configMINIMAL_STACK_SIZE , NULL, 2, NULL);
    
    //cantask
    xTaskCreate(&CanTask, "Can", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    //start so the tasks can start running
    vTaskStartScheduler();

}