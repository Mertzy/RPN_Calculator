#include<vector>

#ifndef STACK
#define STACK

class Stack{
 public:
  Stack();
  int length();
  void push(float);
  void push(int);
  float pop();
  float peek();
  void clear();
 private:
  int len;
  std::vector<float> floatStack;
};
#endif
