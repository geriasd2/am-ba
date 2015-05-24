#include "widget.h"
#include <graphics.hpp>
using namespace genv;
widget::widget(int a,int b,int c,int d){
  x=a;y=b;szelesseg=c;hossz=d;
kattintx=0;kattinty=0;mukodj=false;focus=false;




    //ctor
    }

widget::~widget()
{
    //dtor
}
void widget:: rajzol (){};
void widget:: dolgozik(){};
void widget:: focusfv(){};
