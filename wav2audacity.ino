#include <Arduino.h>
#include "waveheader.h"

// Define the ADC pin
const int adcPin = A0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200); // Use the appropriate baud rate supported by your Arduino and Audacity
  while (!Serial) {
    ; // Wait for serial connection
  }
delayMicroseconds(100);
  // Print the WAV header
  Serial.write((uint8_t*)&wavHeader, sizeof(wavHeader));
}

void loop() {
  // Simulating audio recording
  const uint32_t recordedDataSize = 1024;
  uint8_t recordedData[recordedDataSize];

  // Read audio data from the ADC
  for (uint32_t i = 0; i < recordedDataSize; i++) {
    recordedData[i] = analogRead(adcPin) >> 2; // Adjust the bit shifting to match your ADC resolution
    delayMicroseconds(10); // Adjust the delay as needed for your sampling rate
  }

  // Save the recorded audio data to the buffer
  saveAudioData(recordedData, recordedDataSize);

  // Retrieve the WAV data from the buffer
  uint8_t wavData[maxBufferSize + sizeof(wavHeader)];
  uint32_t wavDataSize;
  getWavData(wavData, &wavDataSize);

  // Send the WAV data to Audacity via Serial communication
  Serial.write(wavData, wavDataSize);

  // Reset the buffer position for the next recording
  bufferPosition = 0;

  // Continue recording or do other tasks
}
