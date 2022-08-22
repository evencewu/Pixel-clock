#ifndef MOD_TIMES_H
#define MOD_TIMES_H
//时间模块

#include "grap_git.h"


  
class Times : public Module
{
  public:
    Times(void); 
    void Grap_num(int num,int order);//数字加载
    void setup_led_perfps(int hours,int minutes);//每帧图像的处理
    void setup_led_purecolor(int h,int s,int v);
  private:
    //动画
    void linear_animation(void);
    void no_animation(void);
    
    int buffer_[17][5][3];
    int target_[17][5][3];
};

//构造函数初始化mod
Times::Times(){
  size_[X] = 17;
  size_[Y] = 5;
  init_pos[X] = 13;
  init_pos[Y] = 3;
  
  for(int loc_x = 0;loc_x <= size_[X]; loc_x++)
  {
    for(int loc_y = 0;loc_y <= size_[Y]; loc_y++)
    {
      buffer_[loc_x][loc_y][0] = 0;
      buffer_[loc_x][loc_y][1] = 0;
      buffer_[loc_x][loc_y][2] = 0;
    }
  }
  
  for(int loc_x = 0;loc_x <= size_[X]; loc_x++)
  {
    for(int loc_y = 0;loc_y <= size_[Y]; loc_y++)
    {
      target_[loc_x][loc_y][0] = 0;
      target_[loc_x][loc_y][1] = 0;
      target_[loc_x][loc_y][2] = 0;
    }
  }
}

//无动画
void Times::no_animation(void)
{
  for(int loc_x = 0;loc_x < size_[X]; loc_x++)
  {
    for(int loc_y = 0;loc_y < size_[Y]; loc_y++)
    {
      buffer_[loc_x][loc_y][0] = target_[loc_x][loc_y][0];
      buffer_[loc_x][loc_y][1] = target_[loc_x][loc_y][1];
      buffer_[loc_x][loc_y][2] = target_[loc_x][loc_y][2];
    }
  } 
}

//线性动画
void Times::linear_animation(void)
{
  for(int loc_x = 0;loc_x < size_[X]; loc_x++)
  {
    for(int loc_y = 0;loc_y < size_[Y]; loc_y++)
    {
      if(buffer_[loc_x][loc_y][0] > target_[loc_x][loc_y][0])       {buffer_[loc_x][loc_y][0] = buffer_[loc_x][loc_y][0] -1;}
      else if(buffer_[loc_x][loc_y][0] < target_[loc_x][loc_y][0])  {buffer_[loc_x][loc_y][0] = buffer_[loc_x][loc_y][0] +1;}  

      if(buffer_[loc_x][loc_y][1] > target_[loc_x][loc_y][1])       {buffer_[loc_x][loc_y][1] = buffer_[loc_x][loc_y][1] -1;}
      else if(buffer_[loc_x][loc_y][1] < target_[loc_x][loc_y][1])  {buffer_[loc_x][loc_y][1] = buffer_[loc_x][loc_y][1] +1;} 

      if(buffer_[loc_x][loc_y][2] > target_[loc_x][loc_y][2])       {buffer_[loc_x][loc_y][2] = buffer_[loc_x][loc_y][2] -1;}
      else if(buffer_[loc_x][loc_y][2] < target_[loc_x][loc_y][2])  {buffer_[loc_x][loc_y][2] = buffer_[loc_x][loc_y][2] +1;} 
    }
  } 
}


void Times::setup_led_purecolor(int h,int s,int v)
{
  for(int loc_x = 0;loc_x < size_[X]; loc_x++)
  {
    for(int loc_y = 0;loc_y < size_[Y]; loc_y++)
    {
      target_[loc_x][loc_y][0] = h;
      target_[loc_x][loc_y][1] = s;
      target_[loc_x][loc_y][2] = v;
    }
  }  
}

void Times::setup_led_perfps(int hours,int minutes)
{
  linear_animation();
  
  Grap_num((int)hours/10,0);
  Grap_num((int)hours%10,4);
  
  Grap_num((int)minutes/10,10);
  Grap_num((int)minutes%10,14);
  
}

void Times::Grap_num(int num,int order){
  if (num == 0)
  {
    for(int i = 0;i < (int)(sizeof(grap_zero)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_zero[i][X]+order,
                  grap_zero[i][Y]      ,
                  buffer_[grap_zero[i][X]+order-1][grap_zero[i][Y]-1][0],
                  buffer_[grap_zero[i][X]+order-1][grap_zero[i][Y]-1][1],
                  buffer_[grap_zero[i][X]+order-1][grap_zero[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 1){
    for(int i = 0;i < (int)(sizeof(grap_one)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_one[i][X]+order,
                  grap_one[i][Y]      ,
                  buffer_[grap_one[i][X]+order-1][grap_one[i][Y]-1][0],
                  buffer_[grap_one[i][X]+order-1][grap_one[i][Y]-1][1],
                  buffer_[grap_one[i][X]+order-1][grap_one[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 2){
    for(int i = 0;i < (int)(sizeof(grap_two)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_two[i][X]+order,
                  grap_two[i][Y]      ,
                  buffer_[grap_two[i][X]+order-1][grap_two[i][Y]-1][0],
                  buffer_[grap_two[i][X]+order-1][grap_two[i][Y]-1][1],
                  buffer_[grap_two[i][X]+order-1][grap_two[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 3){
    for(int i = 0;i < (int)(sizeof(grap_three)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_three[i][X]+order,
                  grap_three[i][Y]      ,
                  buffer_[grap_three[i][X]+order-1][grap_three[i][Y]-1][0],
                  buffer_[grap_three[i][X]+order-1][grap_three[i][Y]-1][1],
                  buffer_[grap_three[i][X]+order-1][grap_three[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 4){
    for(int i = 0;i < (int)(sizeof(grap_four)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_four[i][X]+order,
                  grap_four[i][Y]      ,
                  buffer_[grap_four[i][X]+order-1][grap_four[i][Y]-1][0],
                  buffer_[grap_four[i][X]+order-1][grap_four[i][Y]-1][1],
                  buffer_[grap_four[i][X]+order-1][grap_four[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 5){
    for(int i = 0;i < (int)(sizeof(grap_five)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_five[i][X]+order,
                  grap_five[i][Y]      ,
                  buffer_[grap_five[i][X]+order-1][grap_five[i][Y]-1][0],
                  buffer_[grap_five[i][X]+order-1][grap_five[i][Y]-1][1],
                  buffer_[grap_five[i][X]+order-1][grap_five[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 6){
    for(int i = 0;i < (int)(sizeof(grap_six)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_six[i][X]+order,
                  grap_six[i][Y]      ,
                  buffer_[grap_six[i][X]+order-1][grap_six[i][Y]-1][0],
                  buffer_[grap_six[i][X]+order-1][grap_six[i][Y]-1][1],
                  buffer_[grap_six[i][X]+order-1][grap_six[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 7){
    for(int i = 0;i < (int)(sizeof(grap_seven)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_seven[i][X]+order,
                  grap_seven[i][Y]      ,
                  buffer_[grap_seven[i][X]+order-1][grap_seven[i][Y]-1][0],
                  buffer_[grap_seven[i][X]+order-1][grap_seven[i][Y]-1][1],
                  buffer_[grap_seven[i][X]+order-1][grap_seven[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 8){
    for(int i = 0;i < (int)(sizeof(grap_eight)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_eight[i][X]+order,
                  grap_eight[i][Y]      ,
                  buffer_[grap_eight[i][X]+order-1][grap_eight[i][Y]-1][0],
                  buffer_[grap_eight[i][X]+order-1][grap_eight[i][Y]-1][1],
                  buffer_[grap_eight[i][X]+order-1][grap_eight[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }else if (num == 9){
    for(int i = 0;i < (int)(sizeof(grap_nine)/(2*sizeof(int)));i++)
    {
      turn_screen(grap_nine[i][X]+order,
                  grap_nine[i][Y]      ,
                  buffer_[grap_nine[i][X]+order-1][grap_nine[i][Y]-1][0],
                  buffer_[grap_nine[i][X]+order-1][grap_nine[i][Y]-1][1],
                  buffer_[grap_nine[i][X]+order-1][grap_nine[i][Y]-1][2],
                  init_pos[X],init_pos[Y]);
    }
  }
}



#endif
