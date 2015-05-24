#include "gepeles.h"
#include <graphics.hpp>
gepeles::gepeles (int a, int b): widget (a,b,30,150){
    szovegkiir="";
    //ctor
}

gepeles::~gepeles()
{
    //dtor
}
void gepeles::rajzol(){
genv::gout<<genv::move_to(x,y)<<genv::color(0,0,0)<<genv::line(hossz,0)<<genv::line(0,szelesseg)<<genv::line(-hossz,0)<<genv::line(0,-szelesseg);
if (focus==true){
    genv::gout<<genv::move_to(x-5,y-5)<<genv::color(0,0,255)<<genv::line(hossz+10,0)<<genv::line(0,szelesseg+10)<<genv::line(-hossz-10,0)<<genv::line(0,-szelesseg-10);

    genv::gout<<genv::color(0,0,0)<<genv::move_to(x+5,y+15)<<genv::text(szovegkiir);
    }
}



void gepeles::dolgozik(){
 if (focus==true){
        if (keyertek==8 && szovegkiir.size()!=0){
    szovegkiir.pop_back();
 keyertek=0;
 }
 else if (keyertek!=8 && keyertek!=0 && genv::gout.twidth(szovegkiir)<hossz-10){

    std::string temp;
    temp=keyertek;
     szovegkiir+=temp;
     keyertek=0;
 }

}
}





void gepeles:: focusfv(){
if (kattintx>x && kattintx<x+hossz && kattinty>y && kattinty<y+szelesseg){
    focus=true;
    kattintx=0;
    kattinty=0;
 }
 else if (kattintx!=0 && kattinty!=0){
    focus=false;

  }
}
