#include "amoba.h"
#include <graphics.hpp>

amoba::amoba(int a,int b): widget(a,b,400,400){
for (unsigned int i=0;i<10;i++){
        for (unsigned int j=0;j<10;j++){

            gomb g (a+j*40,b+i*40,40,40,"");
            v.push_back(g);
        }
    }
    jatek=true;
}

amoba::~amoba(){
    //dtor
}


void amoba:: rajzol(){
if (jatek==true){
for (unsigned int i=0;i<v.size();i++){

    v[i].rajzol();}

    }

    else {
     genv::gout<<genv::move_to(x,y)<<genv::color(0,0,0)<<genv::text("vege");
    }
};
void amoba::dolgozik(){};
void amoba:: focusfv(){};
