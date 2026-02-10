#pragma once

#define PACKET_SIZE 16 // Packet size

#define PACKET_SOF     0xA5 // Fixed Start of Frame byte
#define PACKET_VERSION 0x01 // Fixed packet version number

#define PACKET_SOF_OFFSET        0 // Start of Frame offset
#define PACKET_VERSION_OFFSET    1 // Packet Version offset
#define PACKET_STATUS_OFFSET     2 // Status Flags offset
#define PACKET_IR_OFFSET         3 // IR State offset
#define PACKET_ENCODER_OFFSET    4 // Encoder Count offset (4 bytes)
#define PACKET_HALL_OFFSET       8 // Hall ADC Value offset (2 bytes)
#define PACKET_TIMESTAMP_OFFSET 10 // Timestamp offset (2 bytes)
#define PACKET_RESERVED_OFFSET  12 // Reserved bytes offset (2 bytes)
#define PACKET_CRC_OFFSET       14 // CRC16 offset (2 bytes)

#define PACKET_CRC_POLY     0x1021 // CRC16-CCITT polynomial
#define PACKET_CRC_INIT     0xFFFF // Initial value for CRC16-CCITT
#define PACKET_CRC_COVERAGE 14     // Number of bytes covered by CRC (bytes 0–13)