// LoRaSender.ino

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

  Serial.println("LoRa Sender");

  // Setup LoRa transceiver module
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(LORA_BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("LoRa initialization successful.");
}

void loop() {
  Serial.println("Sending packet...");

  // Send packet
  LoRa.beginPacket();
  LoRa.print("Hello, LoRa!");
  LoRa.endPacket();

  Serial.println("Packet sent.");

  delay(2000);  // Wait for 2 seconds before sending the next packet
}
