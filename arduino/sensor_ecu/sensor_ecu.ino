#include <cstring>
#include "snapshot.h"
#include "packet.h"
#include "crc16.h"

static uint8_t packet[PACKET_SIZE];

void packet_builder(const snapshot_t& snap) {
  memset(packet, 0, sizeof(packet)); // zero packet buffer

  // write constants
  packet[PACKET_SOF_OFFSET] = PACKET_SOF;
  packet[PACKET_VERSION_OFFSET] = PACKET_VERSION;

  // write snapshot data
  packet[PACKET_STATUS_OFFSET] = snap.status_flags;
  packet[PACKET_IR_OFFSET] = snap.ir_state;

  // serialize multi-byte fields (little-endian)
  packet[PACKET_ENCODER_OFFSET + 0] = (snap.encoder_count >> 0) & 0xFF;
  packet[PACKET_ENCODER_OFFSET + 1] = (snap.encoder_count >> 8) & 0xFF;
  packet[PACKET_ENCODER_OFFSET + 2] = (snap.encoder_count >> 16) & 0xFF;
  packet[PACKET_ENCODER_OFFSET + 3] = (snap.encoder_count >> 24) & 0xFF;

  packet[PACKET_HALL_OFFSET + 0] = (snap.hall_adc >> 0) & 0xFF;
  packet[PACKET_HALL_OFFSET + 1] = (snap.hall_adc >> 8) & 0xFF;

  packet[PACKET_TIMESTAMP_OFFSET + 0] = (snap.timestamp_ms >> 0) & 0xFF;
  packet[PACKET_TIMESTAMP_OFFSET + 1] = (snap.timestamp_ms >> 8) & 0xFF;

  // compute and write CRC16-CCITT over bytes 0–13
  uint16_t crc = bitwise_crc(packet, PACKET_CRC_COVERAGE, PACKET_CRC_INIT, PACKET_CRC_POLY);
  packet[PACKET_CRC_OFFSET + 0] = (crc >> 0) & 0xFF;
  packet[PACKET_CRC_OFFSET + 1] = (crc >> 8) & 0xFF;
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
