/*
  SineWave

  Generates a pre-generated sawtooth-waveform.

  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/dac
*/

#include "analogWave.h" // Include the library for analog waveform generation

// DAC에서 사인파 발진이 생성되기 시작
// 주파수에 따라 압전 버저나 스피커에서 사운드를 생성하는 데 사용
analogWave wave(DAC);   // Create an instance of the analogWave class, using the DAC pin

int freq = 10;  // in hertz, change accordingly

void setup() {
  Serial.begin(115200);  // Initialize serial communication at a baud rate of 115200
  // 시간에 따른 전압을 그래프로 그리면 선이 사인 함수처럼 보이기 때문에 이를 사인파
  //wave.sine(freq);       // Generate a sine wave with the initial frequency
    wave.saw(freq);
}

void loop() {
  // Read an analog value from pin A5 and map it to a frequency range
  freq = map(analogRead(A5), 0, 1024, 0, 10000);

  // Print the updated frequency to the serial monitor
  Serial.println("Frequency is now " + String(freq) + " hz");

  wave.freq(freq);  // Set the frequency of the waveform generator to the updated value
  delay(1000);      // Delay for one second before repeating
}