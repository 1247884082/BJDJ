#include"BJDJ.h"
#include"Arduino.h"
BJDJ::BJDJ(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{     
  pinMode(x1,OUTPUT);
  pinMode(x2,OUTPUT);
  pinMode(x3,OUTPUT);
  pinMode(x4,OUTPUT);
  pinMode(y1,OUTPUT);
  pinMode(y2,OUTPUT);
  pinMode(y3,OUTPUT);
  pinMode(y4,OUTPUT); 
  X1 = x1;
  X2 = x2;
  X3 = x3;
  X4 = x4;
  Y1 = y1;
  Y2 = y2;
  Y3 = y3;
  Y4 = y4; 
}
BJDJ::Feed(int SUDU){
  sudu = SUDU; 
  linshisudu=SUDU; 
  }
BJDJ::XMC(int Xcs)
{ 
  if(Xcs >= 0)
  {  
  for(int j=0;j < Xcs;j++)
  {
    digitalWrite(X1,HIGH);
    delay(sudu);
    digitalWrite(X1,LOW);
    digitalWrite(X2,HIGH);
    delay(sudu);
    digitalWrite(X2,LOW);
    digitalWrite(X3,HIGH);
    delay(sudu);
    digitalWrite(X3,LOW);
    digitalWrite(X4,HIGH);
    delay(sudu);
    digitalWrite(X4,LOW);
  }
  }
  else if(Xcs < 0)
  {
   for(int j=0;j > Xcs;j--)
    {
    digitalWrite(X4,HIGH);
    delay(sudu);
    digitalWrite(X4,LOW);
    digitalWrite(X3,HIGH);
    delay(sudu);
    digitalWrite(X3,LOW);
    digitalWrite(X2,HIGH);
    delay(sudu);
    digitalWrite(X2,LOW);
    digitalWrite(X1,HIGH);
    delay(sudu);
    digitalWrite(X1,LOW);
    }
  }
}
BJDJ::YMC(int Ycs)
{ 
  if(Ycs >= 0)
  {  
  for(int j=0;j < Ycs;j++)
  {
    digitalWrite(Y1,HIGH);
    delay(sudu);
    digitalWrite(Y1,LOW);
    digitalWrite(Y2,HIGH);
    delay(sudu);
    digitalWrite(Y2,LOW);
    digitalWrite(Y3,HIGH);
    delay(sudu);
    digitalWrite(Y3,LOW);
    digitalWrite(Y4,HIGH);
    delay(sudu);
    digitalWrite(Y4,LOW);
  }
  }
  else if(Ycs < 0)
  {
   for(int j=0;j > Ycs;j--)
    {
    digitalWrite(Y4,HIGH);
    delay(sudu);
    digitalWrite(Y4,LOW);
    digitalWrite(Y3,HIGH);
    delay(sudu);
    digitalWrite(Y3,LOW);
    digitalWrite(Y2,HIGH);
    delay(sudu);
    digitalWrite(Y2,LOW);
    digitalWrite(Y1,HIGH);
    delay(sudu);
    digitalWrite(Y1,LOW);
    }
  }
}
BJDJ::G01(int Xn,int Yn)     
{  
  if(Xn>=0 && Yn>=0)    //1.. 输入x>0,y>0，同号
  {
  if(Xn>=Yn)
  {
   for(int i=0;i<Yn;i++)
    {
     BJDJ::XMC(1);
     BJDJ::YMC(1);
     }
    int j=Xn-Yn;
    for(int i=0;i<j;i++)
    {
     BJDJ::XMC(1);
     }
  }
  else if(Xn<Yn)
   {
    for(int i=0;i<Xn;i++)
    {BJDJ::XMC(1);
    BJDJ::YMC(1);}
   int j=Yn-Xn;
   for(int i=0;i<j;i++){
    BJDJ::YMC(1);}
    }
   }
else if(Xn<0 && Yn<0)       //2.. 输入x<0,y<0,同号
  {
    int xn=(0-Xn);
    int yn=(0-Yn);
  if(xn>=yn)
  {
   for(int i=0;i<yn;i++)
    {
     BJDJ::XMC(-1);
     BJDJ::YMC(-1);
     }
    int j=xn-yn;
    for(int i=0;i<j;i++)
    {
     BJDJ::XMC(-1);
     }
  }
  else if(xn<yn)
   {
    for(int i=0;i<xn;i++)
    {
    BJDJ::XMC(-1);
    BJDJ::YMC(-1);
    }
   int j=yn-xn;
   for(int i=0;i<j;i++){
    BJDJ::YMC(-1);
    }
   }
}
else if(Xn<0 && Yn >= 0)   //3.. 输入x<0,y>0，异号
 {
    int xn=(0-Xn);
    int yn=Yn;
  if(xn >= yn)
  {
   for(int i=0;i<yn;i++)
    {
     BJDJ::XMC(-1);
     BJDJ::YMC(1);
     }
    int j=xn-yn;
    for(int i=0;i<j;i++)
    {
     BJDJ::XMC(-1);
     }
  }
  else if(xn<yn)
   {
    for(int i=0;i<xn;i++)
    {
    BJDJ::XMC(-1);
    BJDJ::YMC(1);
    }
   int j=yn-xn;
   for(int i=0;i<j;i++){
    BJDJ::YMC(1);
    }
   }
  }

else if(Xn >= 0 && Yn < 0)   //4.. 输入x>0,y<0，异号
{
    int xn=Xn;
    int yn=(0-Yn);
  if(xn >= yn)
  {
   for(int i=0;i<yn;i++)
    {
     BJDJ::XMC(1);
     BJDJ::YMC(-1);
     }
    int j=xn-yn;
    for(int i=0;i<j;i++)
    {
     BJDJ::XMC(1);
     }
  }
  else if(xn<yn)
   {
    for(int i=0;i<xn;i++)
    {
    BJDJ::XMC(1);
    BJDJ::YMC(-1);
    }
   int j=yn-xn;
   for(int i=0;i<j;i++){
    BJDJ::YMC(-1);
    }
   }
  }

}
BJDJ::G00(int Xn,int Yn){  
  sudu=100;
  int xnn=Xn;
  int ynn=Yn;
 BJDJ::G01(xnn,ynn);
 sudu=linshisudu;
 BJDJ::Feed(sudu);  
}

BJDJ::G02(int Xn,int Yn,int R)
{
  
  
  }
BJDJ::G03(int Xn,int Yn,int R)
{
  
  
  }
BJDJ::Zero()
{  
   pinMode(Xxianwei,INPUT_PULLUP);
   pinMode(Yxianwei,INPUT_PULLUP);  
   sudu=100;
   Xxianweizhi = 0;
   Yxianweizhi = 0;
   Xxianweizhi=digitalRead(Xxianwei);
   Yxianweizhi=digitalRead(Yxianwei);   
      do{ 
        BJDJ::XMC(-1);
        Xxianweizhi=digitalRead(Xxianwei);
         }
      while(Xxianweizhi == 1);
      do{ 
        BJDJ::YMC(-1);
        Yxianweizhi=digitalRead(Yxianwei);
         }
      while(Yxianweizhi == 1);
  
  sudu=linshisudu;
  BJDJ::Feed(sudu);
}




