#ifndef SCREEN_H
#define SCREEN_H

//---init screen mode

#define NUM_LEDS 256       
#define LED_DT 7             
#define LED_TYPE WS2812      
#define COLOR_ORDER GRB  
uint8_t max_bright = 255;

//-------------------
#define X 0
#define Y 1

CRGB leds[NUM_LEDS];     // 建立光带leds

class Screen
{
  public:
    void set_HSV(int x,int y,int h,int s,int v);
  private:
    int size_[2] = {32,8};
};

void Screen::set_HSV(int x,int y,int h,int s,int v)
{
    leds[(((x-1)/8)*8+(8-y))*8+(x-1)%8] = CHSV (h,s,v);
}

#include "module.h"
#endif
