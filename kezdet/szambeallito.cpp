#include "szambeallito.h"
#include <graphics.hpp>
#include <sstream>



using namespace genv;

szambeallito::szambeallito (int a,int b,int c,int d,int e ) : widget (a,b,20,150){
also=c;felso=d;
if (e>=also && e<=felso){
    szamertek=e;

}
}



void szambeallito::rajzol(){
    gout<<color(0,100,200)<<move_to(x,y)<<line(hossz,0)<<line(0,szelesseg)<<line(-hossz,0)<<line(0,-szelesseg);
gout<<move_to(x+hossz,y)<<color(0,120,200)<<box(-20,szelesseg);
gout<<color(0,0,0)<<move_to(x+hossz,y+szelesseg/2)<<line(-20,0)<<line(10,-szelesseg/2)<<line(11,szelesseg/2);
gout<<line(-10,szelesseg/2)<<line(-11,-szelesseg/2);




gout<<move_to(x,y+szelesseg+10)<<color(220,220,220)<<box(hossz,szelesseg)<<move_to(x,y+szelesseg+10)<<color(180,180,180)<<box(20,20)<<genv::move(-1,-1)<<color(0,0,0)<<line(-19,-10)<<line(19,-10)<<line(0,20);  //also jobb kocka





gout<<move_to(x+hossz,y+szelesseg+10)<<color(180,180,180)<<box(-20,20)<<genv::move(1,-1)<<color(0,0,0)<<line(19,-10)<<line(-19,-10)<<line(0,20);
if (focus==true){
    gout<<move_to(x-5,y-5)<<color(0,100,0)<<line(hossz+10,0)<<line(0,szelesseg+10)<<line(-hossz-10,0)<<line(0,-szelesseg-10);
}

}

void szambeallito::dolgozik(){
 if (keyertek>=47 && keyertek<=57 && focus==true){
      if (mukodj==false){
        szamertek=0;
        ertekir="";
      }

        char a;
        a=keyertek;
std::        string temp=ertekir+a;
std::        stringstream ss;
        ss<<temp;
        int temp2;
        ss>>temp2;
        ss.clear();
        mukodj=true;
        if (temp2>=also && temp2<=felso){
            ertekir+=a;
            ss<<ertekir;
            ss>>szamertek;
            ss.clear();

        }
         keyertek=0;
         kattintx=0;
         kattinty=0;

    }

    if (keyertek==8 && ertekir.size()!=0){
         ertekir.pop_back();
             keyertek=0;
             kattintx=0;
             kattinty=0;

    }


if (kattintx>=x+hossz-20 && kattintx<=x+hossz && kattinty<=y+szelesseg/2 && kattinty>=y && szamertek<felso){
std::    stringstream ss;
    szamertek+=1;
  ss<<szamertek;
  ss>>ertekir;
  kattintx=0;
  kattinty=0;
  mukodj=false;
}
else if(kattintx>=x+hossz-20 && kattintx<=x+hossz && kattinty>=y+szelesseg/2 && kattinty<=y+szelesseg && szamertek>also){
std:: stringstream ss;
    szamertek-=1;
  ss<<szamertek;
  ss>>ertekir;
  kattintx=0;
  kattinty=0;
  mukodj=false;
}
else if (kattintx>=x+hossz-20 && kattintx<=x+hossz && kattinty<=y+szelesseg+30 && kattinty>=y+szelesseg+10 && szamertek<felso){
std::stringstream ss;
    szamertek+=1;
  ss<<szamertek;
  ss>>ertekir;
  kattintx=0;
  kattinty=0;
  mukodj=false;
}
if(kattintx>=x && kattintx<=x+20 && kattinty<=y+szelesseg+30 && kattinty>=y+szelesseg+10 && szamertek>also){
std::  stringstream ss;
    szamertek-=1;
  ss<<szamertek;
  ss>>ertekir;
  kattintx=0;
  kattinty=0;
  mukodj=false;
}


if(kattintx>=x+20 && kattintx<=x+hossz-20 && kattinty<=y+szelesseg+30 && kattinty>=y+szelesseg+10){
std::  stringstream ss;
    double temp=felso-also;
    kattintx-=(x+20);
    double temp2=hossz-40;
    double szorzo=kattintx/temp2;
    szamertek=szorzo*temp+also;
  ss<<szamertek;
  ss>>ertekir;
  kattintx=0;
  kattinty=0;
  mukodj=false;
}


gout<<color(0,0,0)<<move_to(x+3,y+15)<<text(ertekir);


double temp=felso-also;
double temp2=szamertek-also;
double szorzo=temp2/temp;
if (szamertek!=felso){
gout<<color(180,180,180)<<move_to(x+szorzo*(hossz-40)+19,y+szelesseg+10)<<box(6,20); //csuszka
}
else {
    gout<<color(180,180,180)<<move_to(x+hossz-25,y+szelesseg+10)<<box(6,20);
}

}


void szambeallito:: focusfv(){
if(kattintx>=x && kattintx <=x+hossz-20 && kattinty>=y && kattinty<=y+szelesseg){
    focus=!focus;
    kattintx=0;
  kattinty=0;
  mukodj=false;}
  else if (kattintx!=0 && kattinty!=0){
    focus=false;
    mukodj=false;
  }
}

szambeallito::~szambeallito(){
    //dtor
}





