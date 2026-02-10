# include "crc16.h"

uint16_t bitwise_crc(const uint8_t* data, size_t length, uint16_t init, uint16_t poly) {
    uint16_t crc = init; // Initialize CRC with the provided initial value

    // Process each byte of the input data
    for (size_t i = 0; i < length; i ++) {
        crc = crc ^ (data[i] << 8); // XOR the byte into the upper 8 bits of the CRC

        // Process each bit in the current byte
        for (uint16_t j = 0; j < 8; j++) {
            // check if MSB is set
            if ((crc & 0x8000) != 0) { 
                crc = (crc << 1) ^ poly; // Shift left and XOR with polynomial
            } else {
                crc = crc << 1; // shift left
            }
        }
    }
    return crc;
}