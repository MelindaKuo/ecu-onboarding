

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION 1
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configTICK_TYPE_WIDTH_IN_BITS TICK_TYPE_WIDTH_32_BITS
#define configTICK_RATE_HZ ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES ( 4 )
#define configMINIMAL_STACK_SIZE ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE ( ( size_t ) ( 4096 * 4 ) )

#define configUSE_EVENT_GROUPS 0
#define configUSE_STREAM_BUFFERS 0

#define INCLUDE_vTaskDelay 1

#define configASSERT( x )             \
    if( ( x ) == 0 )                  \
    {                                 \
        taskDISABLE_INTERRUPTS();     \
        for( ; ; )                    \
        ;                             \
    }

#endif 
