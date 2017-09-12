#ifndef BJDJ_H_
#define BJDJ_H_
#include <Arduino.h>
#include "BJDJ.h"
class BJDJ{
  public:
    BJDJ(int X1,int X2,int X3,int X4,int Y1,int Y2,int Y3,int Y4);
    int XMC(int Xcs);
    int YMC(int Ycs);
    Feed(int SUDU);
    G00(int Xn,int Yn);
    G01(int Xn,int Yn);    
    G02(int Xn,int Yn,int R);//顺时针
    G03(int Xn,int Yn,int R);//逆时针
    Zero();
    
  private:
  int X1;
  int X2;
  int X3;
  int X4;
  int Y1;
  int Y2;
  int Y3;
  int Y4;
  int Xcs;
  int Ycs;
  int SUDU;
  int sudu;
  int linshisudu;
  int Xn;
  int Yn;
  int R;
  int Xxianwei=10;
  int Yxianwei=11;
  int Xxianweizhi=0;
  int Yxianweizhi=0;







  
};
#endif 
