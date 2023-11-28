// UNO R4 WiFi의 RTC는 Renesas 코어 에 포함된 RTC 라이브러리를 사용하여 액세스
// 시간을 설정/가져올 수 있을 뿐만 아니라 알람을 사용하여 인터럽트를 트리거
#include "RTC.h"

void setup() {
  Serial.begin(9600);

  RTC.begin();
  
  // RTC의 시작 시간을 설정하려면 일, 월, 연도, 시, 분, 초를 지정하고 요일과 일광 절약 모드를 지정
  RTCTime startTime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);

  // setTime() : 시간을 설정
  RTC.setTime(startTime);
}

void loop() {
  RTCTime currentTime;

  // Get current time from RTC
  // getTime() : 현재 시간을 가져오는 메서드
  RTC.getTime(currentTime);
  
  //Unix timestamp
  Serial.print("Unix timestamp: ");
  Serial.println(currentTime.getUnixTime());

  delay(1000);
}