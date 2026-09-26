# What the Project Does

Simulates a sensor ECU that reads a virtual randomized sensor value, applies a moving average of 3 values, then transmits the data over a simulated CAN frame.

# How to Compile and Run

Open this folder in VSCode with the PlatformIO extension installed.
Click the checkmark icon at the bottom to build.
Click the arrow icon at the bottom to run it.
It prints CAN frames forever. Press Ctrl+C in the terminal to stop it.

# CAN ID and Byte Layout

CAN ID: 0x123
Byte 0-1: filtered value (0-100%), sent as the value times 100
Byte 2: error flag (0 = OK, 1 = error)

# Scaling and Error Flag

The value is multiplied by 100 before sending so it can be sent as a whole number instead of a float. Example: 47.5% becomes 4750.
The error flag is set to 1 if the filtered value is below 0 or above 100.
