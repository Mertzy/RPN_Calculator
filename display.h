#include<FL/Fl_Output.H>
#include<string.h>
#include"stack.h"

#ifndef DISPLAY
#define DISPLAY

class Display : public Fl_Output{
 public:
  Display(int x, int y, int w, int h, char* label);
  void input(int);
  void input(float);
  void input(char);
 private:
  bool decimal;
  int numDecimal;
  bool entering;
  float top=0;;
  Stack displayStack;
};
#endif
