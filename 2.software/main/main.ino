#include "FastLED.h"   // 此示例程序需要使用FastLED库

#include "screen.h"

Times times1;

void setup() { 
 
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化光带
  
  FastLED.setBrightness(max_bright);                            // 设置光带亮度
}
 
void loop () { 
  times1.setup_led_perfps();
  FastLED.show();          
  delay(10);       
}
