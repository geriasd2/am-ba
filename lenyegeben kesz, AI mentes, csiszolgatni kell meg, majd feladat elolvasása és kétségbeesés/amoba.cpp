#include "amoba.h"
#include <graphics.hpp>
#include <iostream>
amoba::amoba(int a,int b): widget(a,b,400,400){
for (unsigned int i=0;i<10;i++){
        for (unsigned int j=0;j<10;j++){

            gomb g (a+j*40,b+i*40,40,40,"");
            v.push_back(g);

        }
    }
    hanyadik=0;
    jatek=true;
focus=true;
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
     genv::gout<<genv::move_to(x,y)<<genv::color(0,0,0)<<genv::text(kinyert);
    }
};




void amoba::dolgozik(){
  int temp=0;
for (unsigned int i=0;i<v.size();i++){
        v[i].kattintx=kattintx;
        v[i].kattinty=kattinty;
        v[i].dolgozik();
        if (v[i].focus==true && v[i].szoveg==""){
                hanyadik+=1;
            if (hanyadik % 2 ==0){
                v[i].szoveg="X";
                temp=i;
                i=v.size();
            }
            else {v[i].szoveg="O";
            temp=i;
            i=v.size();}
        }

}

if (v[temp].szoveg=="X"){
    for (unsigned int j=0;j<10;j++){
if (temp<j*10+4 ){
    std::vector <gomb> v1(v.begin()+j*10, v.begin()+temp+4);
//std::cout<<"beleptem a egyesbe- j="<<j<<"temp ="<<temp<<std::endl;
j=10;
 unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
    kinyert="X nyert";
}
    }
    else {sum=0;}
}


}
else if (temp>=j*10+4 && temp<=j*10+6){
std::   vector <gomb> v1(v.begin() + temp-4, v.begin() + temp + 4);
//std::cout<<"beleptem a kettesbe- j="<<j<<"temp ="<<temp<<std::endl;
 j=10;
 unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="X nyert";
}
    }
    else {sum=0;}
}

 }
else if ( temp>j*10+6 && temp<(j+1)*10){
    std::vector <gomb> v1(v.begin()+temp-4, v.begin()+j*10+9);
//std::cout<<"beleptem az harmasba - j="<<j<<"temp ="<<temp<<std::endl;
j=10;
unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="X nyert";
}
    }
    else {sum=0;}
}

}
}
unsigned int tizeshelyiertek=0;
for ( int i=0;i<11;i++){
    if (temp-i*10<0){

        tizeshelyiertek=i-1;
        i=11;
    }

}



    std::vector <gomb> v1;

  if (tizeshelyiertek>=temp%10){
    for (unsigned int i=0;i<=temp%10;i++){
         //   std::cout<<"if ag -- "<<std::endl;
    v1.push_back(v[temp-(temp%10-i)*10-temp%10+i]);
    }
    for (unsigned int j=1;j*10+temp+j<=99;j++){
        v1.push_back(v[temp+j*10+j]);
    }

  }
    else {
        for (unsigned int i=0;i<=tizeshelyiertek;i++){
            //    std::cout<<"else ag -- "<<std::endl;
            v1.push_back(v[temp-(tizeshelyiertek-i)*10-tizeshelyiertek+i]);
        }
for (unsigned int j=1;j*10+temp+j<=99;j++){
        v1.push_back(v[temp+j*10+j]);
    }
    }
    unsigned int sum=0;
  for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="X nyert";
}
    }
    else {sum=0;}
}



  std::vector <gomb> v2;

  if (tizeshelyiertek>=9-temp%10){
    for (unsigned int i=0;i<=9-temp%10;i++){
           std::cout<<"if ag2 -- "<<std::endl;       //temp=19
    v2.push_back(v[temp-(9-temp%10-i)*10+9-temp%10-i]);   //19-(9)*10+9
    //std::cout<<"itt meg jo vagyok"<<std::endl;
    }
    for (unsigned int j=1;j*10+temp-j<=99;j++){
        v2.push_back(v[temp+j*10-j]);
    }

  }
    else {

        for (unsigned int i=0;i<=tizeshelyiertek;i++){
               std::cout<<"else ag2 -- "<<tizeshelyiertek<<" - "<<9-temp%10<<std::endl;
            v2.push_back(v[temp-(tizeshelyiertek-i)*10+tizeshelyiertek-i]);
        }
for (unsigned int j=1;j*10+temp-j<=99;j++){
        v2.push_back(v[temp+j*10-j]);
    }
    }
    sum=0;
  for (unsigned int i=0;i<v2.size();i++){
    if (v2[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="X nyert";
}
    }
    else {sum=0;}

}


std::vector <gomb> v3;
for(unsigned int i=0;i<=tizeshelyiertek;i++){
    v3.push_back(v[temp-i*10]);
}
for (unsigned int j=1;j*10+temp<=99;j++){
    v3.push_back(v[temp+j*10]);
}

 for (unsigned int i=0;i<v3.size();i++){
    if (v3[i].szoveg=="X"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="X nyert";
}
    }
    else {sum=0;}

}








} // szoveg=="X" vizsgalatanak vege


else {
        for (unsigned int j=0;j<10;j++){
if (temp<j*10+4 ){
    std::vector <gomb> v1(v.begin()+j*10, v.begin()+temp+4);
//std::cout<<"beleptem a egyesbe- j="<<j<<"temp ="<<temp<<std::endl;
j=10;
 unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
    kinyert="O nyert";
}
    }
    else {sum=0;}
}


}
else if (temp>=j*10+4 && temp<=j*10+6){
std::   vector <gomb> v1(v.begin() + temp-4, v.begin() + temp + 4);
//std::cout<<"beleptem a kettesbe- j="<<j<<"temp ="<<temp<<std::endl;
 j=10;
 unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="O nyert";
}
    }
    else {sum=0;}
}

 }
else if ( temp>j*10+6 && temp<(j+1)*10){
    std::vector <gomb> v1(v.begin()+temp-4, v.begin()+j*10+9);
//std::cout<<"beleptem az harmasba - j="<<j<<"temp ="<<temp<<std::endl;
j=10;
unsigned int sum=0;
for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="O nyert";
}
    }
    else {sum=0;}
}

}
}
unsigned int tizeshelyiertek=0;
for ( int i=0;i<11;i++){
    if (temp-i*10<0){

        tizeshelyiertek=i-1;
        i=11;
    }

}



    std::vector <gomb> v1;

  if (tizeshelyiertek>=temp%10){
    for (unsigned int i=0;i<=temp%10;i++){
         //   std::cout<<"if ag -- "<<std::endl;
    v1.push_back(v[temp-(temp%10-i)*10-temp%10+i]);
    }
    for (unsigned int j=1;j*10+temp+j<=99;j++){
        v1.push_back(v[temp+j*10+j]);
    }

  }
    else {
        for (unsigned int i=0;i<=tizeshelyiertek;i++){
            //    std::cout<<"else ag -- "<<std::endl;
            v1.push_back(v[temp-(tizeshelyiertek-i)*10-tizeshelyiertek+i]);
        }
for (unsigned int j=1;j*10+temp+j<=99;j++){
        v1.push_back(v[temp+j*10+j]);
    }
    }
    unsigned int sum=0;
  for (unsigned int i=0;i<v1.size();i++){
    if (v1[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="O nyert";
}
    }
    else {sum=0;}
}



  std::vector <gomb> v2;

  if (tizeshelyiertek>=9-temp%10){
    for (unsigned int i=0;i<=9-temp%10;i++){
           std::cout<<"if ag2 -- "<<std::endl;       //temp=19
    v2.push_back(v[temp-(9-temp%10-i)*10+9-temp%10-i]);   //19-(9)*10+9
    //std::cout<<"itt meg jo vagyok"<<std::endl;
    }
    for (unsigned int j=1;j*10+temp-j<=99;j++){
        v2.push_back(v[temp+j*10-j]);
    }

  }
    else {

        for (unsigned int i=0;i<=tizeshelyiertek;i++){
               std::cout<<"else ag2 -- "<<tizeshelyiertek<<" - "<<9-temp%10<<std::endl;
            v2.push_back(v[temp-(tizeshelyiertek-i)*10+tizeshelyiertek-i]);
        }
for (unsigned int j=1;j*10+temp-j<=99;j++){
        v2.push_back(v[temp+j*10-j]);
    }
    }
    sum=0;
  for (unsigned int i=0;i<v2.size();i++){
    if (v2[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="O nyert";
}
    }
    else {sum=0;}

}


std::vector <gomb> v3;
for(unsigned int i=0;i<=tizeshelyiertek;i++){
    v3.push_back(v[temp-i*10]);
}
for (unsigned int j=1;j*10+temp<=99;j++){
    v3.push_back(v[temp+j*10]);
}

 for (unsigned int i=0;i<v3.size();i++){
    if (v3[i].szoveg=="O"){
        sum+=1;
        if (sum==5){
    jatek=false;
     kinyert="O nyert";
}
    }
    else {sum=0;}

}


}














kattintx=0;
kattinty=0;



};
























void amoba:: focusfv(){};
