#include "szamologep.h"
#include <sstream>
#include <graphics.hpp>

szamologep::szamologep(int a,int b): widget(a,b,300,500){
{
    ertekir = "0";
unsigned int j=0;
  for (unsigned int i=1;i<10;i++){
    std::stringstream ss;
    ss<<i;
    std:: string temp;
    ss>>temp;
    unsigned int k=(i-1)%3;

    if (k==0){
        j+=1;
    }

    gomb g(a+k*31,b+j*31,30,30,temp);
    v.push_back(g);
muvelet="alapallas";
pushback=true;
  }
}

{gomb g(a,b+4*31,30,30,"0");
v.push_back(g);}
{gomb g(a+31,b+4*31,30,30,"+");
v.push_back(g);}
{gomb g(a+62,b+4*31,30,30,"-");
v.push_back(g);}
{gomb g(a,b+5*31,30,30,"*");
v.push_back(g);}
{gomb g(a+31,b+5*31,30,30,"/");
v.push_back(g);}
{gomb g(a+62,b+5*31,30,30,"=");
v.push_back(g);}



    //ctor
}

szamologep::~szamologep(){
    //dtor
}



void szamologep:: rajzol(){
for (unsigned int i=0;i<v.size();i++){
    v[i].rajzol();
    genv::gout<<genv::move_to(x,y-1)<<genv::color(0,0,0)<<genv::line(93,0)<<genv::line(0,31)<<genv::line(-93,0)<<genv::line(0,-31);
   if (focus!=true){
    genv::gout<<genv::move_to(x-5,y-5)<<genv::color(0,0,255)<<genv::line(103,0)<<genv::line(0,196)<<genv::line(-103,0)<<genv::line(0,-196);
    }
   else {
      genv::gout<<genv::move_to(x-5,y-8)<<genv::color(0,0,255)<<genv::box(103,3)<<genv::box(3,196)<<genv::box(-106,3)<<genv::box(3,-199)
      <<genv::move_to(x+5,y+15)<<genv::color(0,0,0)<<genv::text(ertekir);
      }
}

}




void szamologep:: dolgozik(){
    if (focus==true){
 for (unsigned int i=0;i<v.size();i++){
        v[i].kattintx=kattintx;
        v[i].kattinty=kattinty;

       }
       for (unsigned int i=0;i<v.size();i++){
        v[i].dolgozik();

       }
       for (unsigned int i=0;i<v.size();i++){
        if (v[i].focus==true && i<10 && pushback==true){

            ertekir+=v[i].szoveg;
          std::  stringstream ss;
            ss<<ertekir;
           long long temp;
            ss>>temp;
            ss.clear();
            ss<<temp;
            ss>>ertekir;
            if (genv::gout.twidth(ertekir)>95){
                ertekir="0";
            }
            v[i].focus=false;
            i=v.size();

        }
        else if (v[i].focus==true && i==10 && muvelet=="alapallas"){
          std::stringstream ss;
          ss<<ertekir;
          ss>>vegrehajtas;
          ss.clear();
          ertekir="0";
          muvelet="+";
          pushback=true;
          v[i].focus=false;
        }
        else if (v[i].focus==true && i==11 && muvelet=="alapallas"){
          std::stringstream ss;
          ss<<ertekir;
          ss>>vegrehajtas;
          ss.clear();
          ertekir="0";
          muvelet="-";
          pushback=true;
          v[i].focus=false;
        }
        else if (v[i].focus==true && i==12 && muvelet=="alapallas"){
          std::stringstream ss;
          ss<<ertekir;
          ss>>vegrehajtas;
          ss.clear();
          ertekir="0";
          muvelet="*";
          pushback=true;
          v[i].focus=false;

        }
        else if (v[i].focus==true && i==13 && muvelet=="alapallas"){
          std::stringstream ss;
          ss<<ertekir;
          ss>>vegrehajtas;
          ss.clear();
          ertekir="0";
          muvelet="/";
          pushback=true;
          v[i].focus=false;
        }

         else if (v[i].focus==true && i==14 ){
            if (muvelet=="+"){
                std::stringstream ss;
                ss<<ertekir;
                long long temp;
                ss>>temp;
                ss.clear();
                temp=temp+vegrehajtas;

                ss<<temp;
                ss>>ertekir;

            }

             else if (muvelet=="-"){
                std::stringstream ss;
                ss<<ertekir;
                long long temp;
                ss>>temp;
                ss.clear();
                temp=vegrehajtas-temp;

                ss<<temp;
                ss>>ertekir;

            }
             else  if (muvelet=="*"){
                std::stringstream ss;
                ss<<ertekir;
                long long temp;
                ss>>temp;
                ss.clear();
                temp=temp*vegrehajtas;

                ss<<temp;
                ss>>ertekir;

            }
             else  if (muvelet=="/"){
                std::stringstream ss;
                ss<<ertekir;
                long long temp;
                ss>>temp;
                ss.clear();
                temp=vegrehajtas/temp;

                ss<<temp;
                ss>>ertekir;

            }
         v[i].focus=false;
        pushback=false;
        muvelet="alapallas";
        }
       }
   if (keyertek==8 && focus==true){
    vegrehajtas=0;
    ertekir="0";
    muvelet="alapallas";
    pushback=true;
    keyertek=0;
   }
    }

}




void szamologep:: focusfv(){
    if (kattintx>x && kattintx<x+93 && kattinty>y && kattinty<y+186){
        focus=true;
        kattintx=0;kattinty=0;
    }
    else if (kattintx!=0 && kattinty!=0){
        focus=false;}
}
