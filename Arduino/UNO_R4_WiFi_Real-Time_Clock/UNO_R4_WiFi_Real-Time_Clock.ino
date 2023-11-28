// UNO R4 WiFi의 RTC는 Renesas 코어 에 포함된 RTC 라이브러리를 사용하여 액세스
// 시간을 설정/가져올 수 있을 뿐만 아니라 알람을 사용하여 인터럽트를 트리거
// Include the RTC library
#include "RTC.h"

// Include the NTP library
#include <NTPClient.h>

#if defined(ARDUINO_PORTENTA_C33)
#include <WiFiC3.h>
#elif defined(ARDUINO_UNOWIFIR4)
#include <WiFiS3.h>
#endif

#include <WiFiUdp.h>
#include "arduino_secrets.h"

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID; // your network SSID (name)
char pass[] = SECRET_PASS; // your network password (use for WPA, or use as key for WEP)

int wifiStatus = WL_IDLE_STATUS;
WiFiUDP Udp; // A UDP instance to let us send and receive packets over UDP

// 현재 시간을 검색하고 저장하기 위해 NTP 서버에 요청
NTPClient timeClient(Udp);
RTCTime currentTime;
volatile bool irqFlag = false;

void printWifiStatus()
{
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void connectToWiFi()
{
    // check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE)
    {
        Serial.println("Communication with WiFi module failed!");
        // don't continue
        while (true)
            ;
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION)
    {
        Serial.println("Please upgrade the firmware");
    }

    // attempt to connect to WiFi network:
    while (wifiStatus != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        wifiStatus = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }

    Serial.println("Connected to WiFi");
    printWifiStatus();
}

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;

    connectToWiFi();
    RTC.begin();
    Serial.println("\nStarting connection to server...");
    timeClient.begin();
    timeClient.update();
    Serial.print("hihi");
    auto timeZoneOffsetHours = 9;
    auto unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours * 3600);
    Serial.print("Unix time = ");
    Serial.println(unixTime);
    RTCTime timeToSet = RTCTime(unixTime);
    RTC.setTime(timeToSet);

    // Retrieve the date and time from the RTC and print them

    RTC.getTime(currentTime);
    // 주기적 인터럽트를 사용하면 반복 콜백을 설정 (알람 콜백 함수, alarmtime 기간)
    if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_1_SEC))
    {
        Serial.println("ERROR: periodic callback not set");
    }
}

void loop()
{
    // Get the current date and time from an NTP server and convert
    // it to UTC +2 by passing the time zone offset in hours.
    // You may change the time zone offset to your local one.
    if (irqFlag)
    {
        auto timeZoneOffsetHours = 9;
        auto unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours * 3600);
        Serial.print("Unix time = ");
        Serial.println(unixTime);
        RTCTime timeToSet = RTCTime(unixTime);
        RTC.setTime(timeToSet);

        // Retrieve the date and time from the RTC and print them

        RTC.getTime(currentTime);
        Serial.println("The RTC was just set to: " + String(currentTime));
        irqFlag = false;
    }
}

// 1초마다 시간 변경
void periodicCallback()
{
    irqFlag = true;
}