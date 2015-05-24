#include "valasztos1.h"
#include <graphics.hpp>

valasztos1::valasztos1(int a,int b,vector <sztring> s): widget (a,b,0,0){
v=s;
x=a;y=b;ertek=0;mukodj=false;
int temp=0;
if (v.size()!=0){
temp=genv::gout.twidth(v[0].szoveg);
}
for (unsigned int i=1;i<v.size();i++){
if (genv::gout.twidth(v[i].szoveg)>temp){
    temp=genv::gout.twidth(v[i].szoveg);
}

}
igazit=temp;
}

valasztos1::~valasztos1(){
    //dtor
}



void valasztos1::rajzol(){
 genv::gout<<genv::move_to(x,y)<<genv::color(220,220,220)<<genv::box(igazit+50,110)<<genv::move(0,-109)<<genv::color(180,180,180)<<genv::box(-20,20)<<genv::color(0,0,0)<<genv::line(10,-19)<<genv::line(10,19)<<genv::line(-20,0)
    <<genv::move(0,1)<<genv::color(230,230,230)
<<genv::box(20,71)<<genv::color(180,180,180)<<genv::box(-20,20)<<genv::color(0,0,0)
<<genv::move(1,-19)<<genv::line(20,0)<<genv::line(-10,19)<<genv::line(-10,-19);


 for (unsigned int i=0;i<v.size();i++){
    if (v[i].mutat==true && i>=ertek && i<=ertek+4){
          //  cout<<i<<endl;
        genv::gout<<genv::move_to(x,y+(i-ertek)*20+5)<<genv::color(0,0,200)<<genv::box(genv::gout.twidth(v[i].szoveg),20);
   }
}

if (v.size()!=0){
 unsigned int j=0;
if (v.size()<5){
        for (unsigned int i=0;i<v.size();i++){
    genv::gout<<genv::move_to(x,y+(j+1)*20)<<genv::color(0,0,0)<<genv::text(v[i].szoveg);
    j+=1;
        }
 }
else {
    for (unsigned int i=ertek;i<ertek+5;i++){

        genv::gout<<genv::move_to(x,y+(j+1)*20)<<genv::color(0,0,0)<<genv::text(v[i].szoveg);
          j+=1;
    }
 }

}

}



void valasztos1::dolgozik(){
if (keyertek==5 && ertek<v.size()-5){
    ertek+=1;
    keyertek=0;

}
if (keyertek==4 && ertek>0){
    ertek-=1;
    keyertek=0;

}

if (kattintx>=x+igazit+30 && kattintx<=x+igazit+50 && kattinty>=y && kattinty<=y+20 && ertek>0){
    ertek-=1;
    kattintx=0;
    kattinty=0;

}
if (kattintx>=x+igazit+30 && kattintx<=x+igazit+50 && kattinty>=y+90 && kattinty<=y+110 && ertek<v.size()-5){
    ertek+=1;
    kattintx=0;
    kattinty=0;

}
if (kattintx>=x+igazit+30 && kattintx<=x+igazit+50 && kattinty>=y+20 && kattinty<=y+90){

    double temp=v.size()-5;
    kattinty-=(y+20);
    double temp2=70;
    double szorzo=kattinty/temp2;
    ertek=szorzo*temp;
  kattintx=0;
  kattinty=0;
 // pozi=ertek;
}
for (unsigned int i=0;i<v.size();i++){
if (kattintx>=x && kattintx<=x+igazit && kattinty>=y+i*20 && kattinty<=y+(i+1)*20 && v[i+ertek].mutat==false){
    for (unsigned int j=0;j<v.size();j++){
        v[j].mutat=false;
    }
    v[i+ertek].mutat=true;


    pozi=ertek+i;
    allando=pozi+ertek;
    kattintx=0;
    kattinty=0;

    mukodj=true;

}
else if (kattintx>=x && kattintx<=x+igazit && kattinty>=y+i*20 && kattinty<=y+(i+1)*20 && v[i+ertek].mutat==true){
    v[i+ertek].mutat=false;
    pozi=ertek+i;
    allando=pozi+ertek;
    kattintx=0;
    kattinty=0;

    mukodj=true;

}
}

double temp=v.size()-5;
double temp2=ertek;
double szorzo=temp2/temp;
if (ertek!=v.size()-5){
genv::gout<<genv::color(180,180,180)<<genv::move_to(x+igazit+29,y+20+szorzo*(70))<<genv::box(20,6);
}
else {

genv::gout<<genv::color(180,180,180)<<genv::move_to(x+igazit+29,y+84)<<genv::box(20,6);

}
}


void valasztos1::focusfv(){}









