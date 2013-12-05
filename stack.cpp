#include"stack.h"

Stack::Stack(){
  this->len=0;
}

void Stack::push(float x){
  this->floatStack.push_back(x);
  this->len++;
}

float Stack::pop(){
  len--;
  return this->floatStack.pop_back();
}

float Stack::peek(){
  return this->floatStack.back();
}

int Stack::length(){
  return this->len;
}
