#include <EEPROM.h>

int addr = 0;
byte value = 100; 

void setup() {
  // EEPROM 메모리에 쓸 때 주소 와 값 이라는 두 가지 매개변수를 지정
  // 각 바이트는 0-255 사이의 값을 보유
  EEPROM.write(addr, value);
}
void loop(){ 
}