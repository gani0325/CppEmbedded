/*
  CANRead

  Receive and read CAN Bus messages

  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/can
*/

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_CAN.h>

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(115200);
  while (!Serial) { }

  if (!CAN.begin(CanBitRate::BR_500k))
  {
    Serial.println("CAN.begin(...) failed.");
    for (;;) {}
  }
}

void loop()
{
  // 데이터가 사용 가능한지 확인
  if (CAN.available())
  {
    // 메시지를 읽기
    CanMsg const msg = CAN.read();
    Serial.println(msg);
  }
}