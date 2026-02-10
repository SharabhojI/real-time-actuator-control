#pragma once
#include <cstdint>

/*
* Snapshot structure to hold the sensor data at a specific point in time.
* Status flag bit allocations:
* Bit 0: Encoder valid, 
* Bit 1: Hall sensor valid, 
* Bit 2: IR sensor valid,
* Bit 3: Sensor task active, 
* Bit 4: Data valid, 
* Bits 5-7: Reserved for future use 
*/
typedef struct {
    int32_t  encoder_count; // Cumulative encoder count
    uint16_t hall_adc;      // Raw ADC value from the hall sensor
    uint8_t  ir_state;      // IR State (0: Clear, 1: Blocked)
    uint8_t  status_flags;  // Bitfield for sensor validity and task status
    uint16_t timestamp_ms;  // Timestamp in milliseconds since system start
} snapshot_t;

enum class StatusFlag : uint8_t {
    EncoderValid = (1 << 0), // Bit 0
    HallValid    = (1 << 1), // Bit 1
    IRValid      = (1 << 2), // Bit 2
    TaskActive   = (1 << 3), // Bit 3
    DataValid    = (1 << 4)  // Bit 4
};