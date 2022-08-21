#ifndef MOD_TIMES_H
#define MOD_TIMES_H

class Times : public Module
{
  public:
    int size_[2] = {17,5};
    int init_pos[2] = {13,3};
    void setup_led_perfps(int hours,int minutes);
  private:
};


void Times::setup_led_perfps(int hours,int minutes)
{
  turn_screen(1,2,80,255,200,init_pos[X],init_pos[Y]);
}
#endif
