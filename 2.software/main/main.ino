#include "FastLED.h"   // 此示例程序需要使用FastLED库
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "screen.h"

Times times1;

const char *ssid     = "EVENCE"; //账号
const char *password = "20040220";//密码

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com"); //NTP地址

void setup() { 
  Serial.begin(115200);
  //WIFI
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
  timeClient.setTimeOffset(28800); 
  //串口
  
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS); 
  FastLED.setBrightness(max_bright);
}
 int i = 0;
void loop () { 
  fill_solid(leds, 256, CHSV (0,0,0));
  
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  
  times1.setup_led_purecolor(i,255,200);
  i++;
  if (i == 256){
    i = 0;
  }
  times1.setup_led_perfps(currentHour,currentMinute);
  FastLED.show();                 
}

 

 
