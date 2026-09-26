// can.h 
// defines a CAN frame layout(ID, filtered val, error flag) and includes functions that build the frame and transmits a frame out


#ifndef CAN_H
#define CAN_H

#include <stdint.h>

#define CAN_ID 0x123

typedef struct{
    uint16_t canID; 
    uint16_t filtVal; 
    uint8_t errFlag; 
} CanFrame;

// formate the Frame into CanFrame format
CanFrame formatFrame(float val, uint8_t err); 

//serial print the frame
void transmitFrame(CanFrame frame); 

//convert a float value from sensor readings to byte 
uint16_t toByte(float val); 


//convert byte values to float sensor readings for easy read
float toFloat(uint16_t b);

#endif
