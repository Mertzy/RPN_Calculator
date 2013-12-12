#include"stack.h"
#include<vector>

Stack::Stack(){
  this->len=0;
}

void Stack::clear(){
  this->len=0;
  this->floatStack.clear();
}

void Stack::push(float x){
  this->floatStack.push_back(x);
  this->len++;
}

void Stack::push(int x){
  this->floatStack.push_back(float(x));
  this->len++;
}

float Stack::pop(){
  len--;
  float temp = this->floatStack.back();
  this->floatStack.pop_back();
  return temp;
}

float Stack::peek(){
  return this->floatStack.back();
}

int Stack::length(){
  return this->len;
}
