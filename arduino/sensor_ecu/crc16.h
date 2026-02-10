#pragma once
#include <cstdint>
#include <cstddef>

uint16_t bitwise_crc(const uint8_t* data, size_t length, uint16_t init, uint16_t poly);