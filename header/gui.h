#ifndef GUI_H
#define GUI_H
#include <graphics.hpp>
#include "widget.h"
#include <vector>


struct gui
{
unsigned int X,Y;
gui(unsigned int a,unsigned int b);

     genv::   event ev;
      std::  vector <widget*> v;









void torol();
void esemeny(unsigned int a);
void pushback(widget *h);
void ujvektoradas (std::vector <widget*> &v1);


};

#endif // GUI_H
