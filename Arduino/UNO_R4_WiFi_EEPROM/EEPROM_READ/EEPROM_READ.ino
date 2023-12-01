#include <EEPROM.h>

int addr = 0;
byte value;

void setup() {
  Serial.begin(9600);
  // EEPROM(전자적으로 지울 수 있는 프로그래밍 가능 읽기 전용 메모리)
  // 정전 후 복구할 수 있는 데이터를 저장하는 데 사용할 수 있는 메모리
  value = EEPROM.read(addr);   // reads first byte
  while (!Serial) {

  }

  Serial.print("Address 0: ");
  Serial.println(value);
}

void loop() {
}