#include "gomb.h"
#include <graphics.hpp>
gomb::gomb(int a,int b,int c,int d,std::string s): widget (a,b,c,d){
    szoveg=s;
focus=false;

    //ctor
}

gomb::~gomb(){
    //dtor
}


void gomb::rajzol(){
genv::gout<<genv::move_to(x,y)<<genv::color(0,0,0)<<genv::line(hossz,0)<<genv::line(0,szelesseg)<<genv::line(-hossz,0)<<genv::line(0,-hossz)
<<genv::move((hossz/2)-5,(szelesseg/2)+5)<<genv::text(szoveg);

}




void gomb:: dolgozik(){

if (kattintx>x && kattintx<x+hossz && kattinty>y && kattinty<y+szelesseg){
focus=true;
kattintx=0;kattinty=0;

}
else {focus=false;}





}
void gomb:: focusfv(){}
