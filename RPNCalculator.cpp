#include"stack.h"
#include<iostream>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>
#include <cstdlib>
#include <cstdio>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include"display.h"

using namespace std;

Display *d;

void b0cb(Fl_Widget *){d->input(int(0));}
void b1cb(Fl_Widget *){d->input(int(1));}
void b2cb(Fl_Widget *){d->input(int(2));}
void b3cb(Fl_Widget *){d->input(int(3));}
void b4cb(Fl_Widget *){d->input(int(4));}
void b5cb(Fl_Widget *){d->input(int(5));}
void b6cb(Fl_Widget *){d->input(int(6));}
void b7cb(Fl_Widget *){d->input(int(7));}
void b8cb(Fl_Widget *){d->input(int(8));}
void b9cb(Fl_Widget *){d->input(int(9));}

void bPluscb(Fl_Widget *){d->input('+');}
void bMinuscb(Fl_Widget *){d->input('-');}
void bMultcb(Fl_Widget *){d->input('*');}
void bDivcb(Fl_Widget *){d->input('/');}
void bPowercb(Fl_Widget *){d->input('^');}
void bSqrtcb(Fl_Widget *){d->input('%');}
void bEntcb(Fl_Widget *){d->input('=');}
void bNegcb(Fl_Widget *){d->input('_');}
void bDotcb(Fl_Widget *){d->input('.');}
void bClrcb(Fl_Widget *){d->input(' ');}

int main(int argc, char **argv){
  Fl_Window *mainWindow = new Fl_Window(250,300,"RPN Calculator\n v0.9");
  d = new Display(10,10,230,40,"");
  d->input(float(4.0));

  Fl_Button *bPlus  = new Fl_Button(10,60,40,40,"+");
  Fl_Button *bMinus = new Fl_Button(55,60,40,40,"-");
  Fl_Button *bMult  = new Fl_Button(100,60,40,40,"*");
  Fl_Button *bDiv   = new Fl_Button(145,60,40,40,"/");
  Fl_Button *b7     = new Fl_Button(10,105,40,40,"&7");
  Fl_Button *b8     = new Fl_Button(55,105,40,40,"&8");
  Fl_Button *b9     = new Fl_Button(100,105,40,40,"&9");
  Fl_Button *bPower = new Fl_Button(145,105,40,40,"&^");
  Fl_Button *b4     = new Fl_Button(10,150,40,40,"&4");
  Fl_Button *b5     = new Fl_Button(55,150,40,40,"&5");
  Fl_Button *b6     = new Fl_Button(100,150,40,40,"&6");
  Fl_Button *bSqrt  = new Fl_Button(145,150,40,40,"Sqrt");
  Fl_Button *b1     = new Fl_Button(10,195,40,40,"&1");
  Fl_Button *b2     = new Fl_Button(55,195,40,40,"&2");
  Fl_Button *b3     = new Fl_Button(100,195,40,40,"&3");
  Fl_Button *bClr   = new Fl_Button(145,195,40,40,"Clr");
  Fl_Button *b0     = new Fl_Button(10,240,40,40,"&0");
  Fl_Button *bNeg   = new Fl_Button(55,240,40,40,"+/-");
  Fl_Button *bDot   = new Fl_Button(100,240,40,40,".");
  Fl_Button *bEnt   = new Fl_Button(145,240,40,40,"Ent");

  b0->callback(b0cb);
  b1->callback(b1cb);
  b2->callback(b2cb);
  b3->callback(b3cb);
  b4->callback(b4cb);
  b5->callback(b5cb);
  b6->callback(b6cb);
  b7->callback(b7cb);
  b8->callback(b8cb);
  b9->callback(b9cb);

  bPlus->callback(bPluscb);
  bMinus->callback(bMinuscb);
  bMult->callback(bMultcb);
  bDiv->callback(bDivcb);
  bPower->callback(bPowercb);
  bSqrt->callback(bSqrtcb);
  bEnt->callback(bEntcb);
  bNeg->callback(bNegcb);
  bDot->callback(bDotcb);
  bClr->callback(bClrcb);

  mainWindow->end();
  mainWindow->show(argc,argv);
  return Fl::run();
}
