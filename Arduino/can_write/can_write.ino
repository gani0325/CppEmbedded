//#include <R7FA2A1AB.h>
#include <Arduino_CAN.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

// 캔 통신에서 송신되는 메세지는 ID가 있으며, 최대 8바이트의 데이터
// 메세지는 버스에 연결된 모든 제어기에게 전송
static uint32_t const CAN_ID = 0x23;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  // TRNG

  Serial.begin(115200);
  while (!Serial)
  {
  }

  // CAN 비트 전송률과 초기 라이브러리
  // CAN 트랜시버가 없으면 다른 CAN 장치와 통신할 수 없음! BR_125k (125000), BR_250k (250000), BR_500k(500000), BR_1000k (1000000)  """
  if (!CAN.begin(CanBitRate::BR_500k))
  {
    Serial.println("CAN.begin(...) failed.");
    for (;;)
    {
    }
  }
}

static uint32_t msg_cnt = 0;

void loop()
{
  //  매번 증가하는 CAN 메시지를 생성
  /* Assemble a CAN message with the format of
   * 0xCA 0xFE 0x00 0x00 [4 byte message counter]
   */
  uint8_t const msg_data[] = {0xCA, 0xFE, 0, 0, 0, 0, 0, 0};

  // 복사 받을 메모리를 가리키는 포인터, 복사할 메모리를 가리키고 있는 포인터, 복사할 데이터(값)의 길이(바이트 단위)
  memcpy((void *)(msg_data + 4), &msg_cnt, sizeof(msg_cnt));
  // CAN 메시지 보낼 객체(CanMsg) : CAN_ID, 크기 및 메시지 데이터
  CanMsg const msg(CanStandardId(CAN_ID), sizeof(msg_data), msg_data);

  /* Transmit the CAN message, capture and display an
   * error core in case of failure.
   */

  // 메시지를 보내기
  if (int const rc = CAN.write(msg); rc < 0)
  {
    Serial.print("CAN.write(...) failed with error code ");
    Serial.println(rc);
    for (;;)
    {
    }
  }

  /* Increase the message counter. */
  msg_cnt++;

  /* Only send one message per second. */
  delay(1000);
}