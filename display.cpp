#include "display.h"
#include<FL/Fl.H>
#include<FL/Fl_Output.H>
#include<string>
#include<iostream>
#include<math.h>

Display::Display(int x, int y, int w, int h, char * label):Fl_Output(x,y,w,h,label){
  this->top=0;
  this->entering=false;
  this->value("");
  this->decimal=false;
  this->numDecimal=1;
}

void Display::input(float x){
}

void Display::input(int x){
  //std::cout<<top<<std::endl;
  if(not decimal){
    this->entering=true;
    this->top=this->top*10;
    this->top=this->top+x;
    this->value(std::to_string(this->top).c_str());
  }
  else{
    float tempNum;
    int divisor = pow(10,numDecimal);
    tempNum=float(x)/(divisor);
    std::cout<<x<<"/"<<divisor<<"="<<tempNum<<std::endl;
    this->top+=(tempNum);
    std::cout<<this->top<<std::endl;
    this->numDecimal++;
    this->value(std::to_string(this->top).c_str());
  }
}

void Display::input(char x){
  //Inputs
  // + - * / ^ % = _ .
  if(x=='='){
    this->entering=false;
    this->value("");
    displayStack.push(this->top);
    this->top=0;
    this->decimal=false;
    this->numDecimal=1;
  }
  
  if(x=='.'){
    this->decimal=true;
  }

  if(x=='_'){
    this->top*=-1;
    this->value(std::to_string(this->top).c_str());
  }
  
  if(x=='+'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float currentVal=0;
    //std::cout<<displayStack.length()<<std::endl;
    if (displayStack.length()>0){
      currentVal=displayStack.pop();
    }
    if (displayStack.length()>0){
      currentVal+=displayStack.pop();
    }
    displayStack.push(currentVal);
    this->value(std::to_string(currentVal).c_str());
  }
  if(x=='-'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float currentVal=0;
    //std::cout<<displayStack.length()<<std::endl;
    if (displayStack.length()>0){
      currentVal=displayStack.pop();
    }
    if (displayStack.length()>0){
      currentVal-=displayStack.pop();
      currentVal=currentVal*-1;
    }
    displayStack.push(currentVal);
    this->value(std::to_string(currentVal).c_str());
  }
  if(x=='*'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float currentVal=0;
    //std::cout<<displayStack.length()<<std::endl;
    if (displayStack.length()>0){
      currentVal=displayStack.pop();
    }
    if (displayStack.length()>0){
      currentVal*=displayStack.pop();
    }
    displayStack.push(currentVal);
    this->value(std::to_string(currentVal).c_str());
  }
  if(x=='/'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float numerator,denominator=0;
    if (displayStack.length()>0){
      denominator=displayStack.pop();
    }
    if (displayStack.length()>0){
      numerator=displayStack.pop();
      denominator=numerator/denominator;
    }
    displayStack.push(denominator);
    this->value(std::to_string(denominator).c_str());
  }
  if(x=='^'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float exponent=0,argument;
    if (displayStack.length()>0){
      exponent=displayStack.pop();
    }
    if (displayStack.length()>0){
      argument=displayStack.pop();
      exponent=pow(argument,exponent);
    }
    displayStack.push(exponent);
    this->value(std::to_string(exponent).c_str());
  }
  if(x=='%'){
    if (this->entering){
      displayStack.push(this->top);
      this->top=0;
      this->entering=false;
    }
    float currentVal=0;
    if (displayStack.length()>0){
      currentVal=displayStack.pop();
      currentVal=pow(currentVal,0.5);
    }
    displayStack.push(currentVal);
    this->value(std::to_string(currentVal).c_str());
  }
  if(x==' '){
    this->displayStack.clear();
    this->top=0;
    this->value("");
    this->decimal=false;
    this->numDecimal=1;
  }
}
