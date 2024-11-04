// LoRaReceiver.ino

#include <SPI.h>
#include <LoRa.h>

// LoRa configuration
#define LORA_SS 5     // Chip select
#define LORA_RST 14   // Reset
#define LORA_DIO0 16  // DIO0
#define LORA_BAND 433E6  // Frequency (Adjust based on your region)

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  // Setup LoRa transceiver module
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(LORA_BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("LoRa initialization successful.");
}

void loop() {
  // Try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.print("Received packet: ");

    // Read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    Serial.println();

    // Print RSSI (Received Signal Strength Indicator)
    Serial.print("RSSI: ");
    Serial.println(LoRa.packetRssi());
  }
}
