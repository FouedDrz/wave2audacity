#include <arduino.h>
#include "waveheader.h"

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  // Print the size of the WAV header structure
  //Serial.print("Raw file");

}

void loop() {
  // Simulating audio recording


  uint8_t recordedData[] = {0x01, 0x02, 0x03, 0x04,0x05,0x06,0x07,0x08,0x09}; 
  // Replace with your actual audio data
  uint32_t recordedDataSize = sizeof(recordedData);
  
  // Save the recorded audio data to the buffer
  saveRawAudioData(recordedData, recordedDataSize);
  delay(1000);
  
  uint8_t* rawAudioData = audioBuffer;
  uint32_t rawAudioDataSize = bufferPosition;
  
  // Print the raw audio data size
  //Serial.print("Raw audio data size: ");
  //Serial.println(rawAudioDataSize);
  
  // Send the raw audio data over serial
  for (uint32_t i = 0; i < rawAudioDataSize; i++) {
    Serial.write(rawAudioData[i]);
  }
 
  bufferPosition = 0;
  
  // Continue recording 
}
