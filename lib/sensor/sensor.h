// sensor.h
// Simulates a virutal sensor, applies a moving-average filter, 
// while detecting out of range values (<0 or > 100)


#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// generate the noise as random
float generateSignal(void);

// the moving average filter of 3 samples
float averageFilter(float newSamples);

//detecting errors
bool detectError(float value);

#endif
