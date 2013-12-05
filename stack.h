#include<vector>

#ifndef STACK
#define STACK

class Stack{
 public:
  Stack();
  int length();
  void push(float);
  float pop();
  float peek();
 private:
  int len;
  std::vector<float> floatStack;
};
#endif
