// UNO R4 WiFi의 RTC는 Renesas 코어 에 포함된 RTC 라이브러리를 사용하여 액세스
// 시간을 설정/가져올 수 있을 뿐만 아니라 알람을 사용하여 인터럽트를 트리거
#include "RTC.h"

volatile bool irqFlag = false;
volatile bool ledState = false;

const int led = LED_BUILTIN;

void setup() {
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  // Initialize the RTC
  RTC.begin();

  // RTC.setTime() must be called for RTC.setPeriodicCallback to work, but it doesn't matter
  // what date and time it's set to
  RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  // 주기적 인터럽트를 사용하면 반복 콜백을 설정 (알람 콜백 함수, alarmtime 기간)
  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop(){
  if(irqFlag){
    Serial.println("Timed CallBack");
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
    irqFlag = false;
  }
}

// 2초마다 표시등이 깜박
void periodicCallback()
{
  irqFlag = true;
}