#include "can.h"
#include <stdio.h>

CanFrame formatFrame(float val, uint8_t err){
    CanFrame c; 
    uint16_t convertedVal = toByte(val);
    c.filtVal = convertedVal; 
    c.errFlag = err; 
    c.canID = CAN_ID; 
    return c; 
}

void transmitFrame(CanFrame frame){
    printf("CAN[ID=0x%X]: %f%%, %s\n", frame.canID, toFloat(frame.filtVal), frame.errFlag ? "ERROR": "OK");
    fflush(stdout);
}

uint16_t toByte(float val){
    float scaledVal = val*100; 
    return (uint16_t) scaledVal; 
}

float toFloat(uint16_t b){
    return (float)b / 100; 
}