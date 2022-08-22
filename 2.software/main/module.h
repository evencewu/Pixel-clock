#ifndef MODULE_H
#define MODULE_H


class Module :public Screen
{
  public:
    int size_[2];
    int init_pos[2];
    void turn_screen(int x,int y,int h,int s,int v,int dx,int dy);
  private:
  
};

void Module::turn_screen(int x,int y,int h,int s,int v,int dx,int dy)
{
  set_HSV(x+dx-1 ,y+dy-1 ,h ,s ,v);
}

#include "mod_times.h"


#endif
