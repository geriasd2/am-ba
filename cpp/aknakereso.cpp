#include "aknakereso.h"
#include <cstdlib>
#include <graphics.hpp>
#include <iostream>
#include <sstream>
aknakereso::aknakereso(int a,int b): widget(a,b,400,400){
    jatek=true;
    for (unsigned int i=0;i<10;i++){
        for (unsigned int j=0;j<10;j++){

            gomb g (a+j*40,b+i*40,40,40,"");
            v.push_back(g);
        }
    }
    for (unsigned int i=0;i<10;i++){
   int temp= rand() % 100;
   std::cout<<temp<<std::endl;
   v1.push_back(temp); }
}

aknakereso::~aknakereso(){
    //dtor
}

void aknakereso :: focusfv(){};
void aknakereso :: dolgozik(){
for (unsigned int i=0;i<v.size();i++){
        v[i].kattintx=kattintx;
        v[i].kattinty=kattinty;
        v[i].dolgozik();

        for (unsigned int j=0;j<v1.size();j++){
    if (v[i].focus==true && i==v1[j] ){
           jatek=false;
    }

    else if ( v[i].focus==true) {
        v[i].szoveg="0";
        for ( int j=0;j<v1.size();j++){
                if (i+1==v1[j]){
            std::        stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i-1==v1[j] ){
                  std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i+10==v1[j]){
                   std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i-10==v1[j]  ){
                    std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i+9==v1[j]){
                   std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i+11==v1[j]){
                    std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i-9==v1[j]){
                    std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (i-11==v1[j]){
                    std::  stringstream ss;
                    ss<<v[i].szoveg;
                    int temp;
                    ss>>temp;
                    temp+=1;
                    ss.clear();
                    ss<<temp;
                    v[i].szoveg.clear();
                    ss>>v[i].szoveg;
                }
                if (v[i].szoveg=="0"){
                   v[i+1]. kattintx+=20;

                }
    }
}
}
}

};
void aknakereso :: rajzol(){
    if (jatek==true){
for (unsigned int i=0;i<v.size();i++){

    v[i].rajzol();}

    }

    else {
     genv::gout<<genv::move_to(x,y)<<genv::color(0,0,0)<<genv::text("vege");
    }
};
