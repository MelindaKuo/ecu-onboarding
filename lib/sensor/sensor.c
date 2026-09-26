#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

static float buffer[3];
static int index; 

// generate the noise as random values using rand() and scaling it to between 0-100
float generateSignal(void){
    return rand() % 101; 
}

// the moving average filter of 3 samples
float averageFilter(float newSample){
    buffer[index%3] = newSample;
    index++; 
    float tot = 0; 
    for(int i  =0; i<3; i++){
        tot += buffer[i]; 
    }
    return tot/3;
}

//detecting errors
bool detectError(float value){
    if(value < 0 || value > 100){
        return true;
    }
    return false; 
}
