#include "amoba.h"
#include <graphics.hpp>
#include <iostream>
amoba::amoba(int a,int b): widget(a,b,10,10){
for (unsigned int i=0;i<40;i++){
        for (unsigned int j=0;j<40;j++){

            gomb g (a+j*20,b+i*20,20,20,"");
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
if (jatek==true){

if (v[temp].szoveg=="X"){



    unsigned int balra,jobbra,keresztbe1,keresztbe2,fel,le;
    balra=0;jobbra=0;keresztbe1=0;keresztbe2=0;fel=0;le=0;
    for ( int i=0;i<=temp%40;i++){
     if(v[temp-i].szoveg=="X" && temp-i>=0){
      balra+=1;
     }
     else{i=temp%40+1;}

    }

    for ( int i=1;temp%40+i<40;i++){
        if(v[temp+i].szoveg=="X" && temp+i<=1599){
            jobbra+=1;

        }
        else {i=41;}
    }

    for (int i=1;temp-i*40>=0;i++){
      if(v[temp-i*40].szoveg=="X"){
       fel+=1;

      }
      else {i=41;}
    }

    for (unsigned int i=0;i*40+temp<1600;i++){
      if(v[temp+i*40].szoveg=="X"){
       le+=1;
      }
      else {i=41;}
    }

    unsigned int i=0;bool h=true;
    while ((temp-i*39)%40!=0 && h==true && temp-i*39>=0){
        if(v[temp-i*39].szoveg=="X"){
            keresztbe1+=1;
            i+=1;
        }
        else {h=false;}
    }


    i=1;h=true;
    while ((temp+i*39)%40!=0 && h==true && temp+i*39<1560){ //javítani kell
      if(v[temp+i*39].szoveg=="X"){
        keresztbe1+=1;
    i+=1;
      }
      else {h=false;}
    }

//jobbrol balra pipa
i=0;h=true;
while ((temp-i*41)%40!=0 && h==true && temp-i*41>=0){
   if(v[temp-i*41].szoveg=="X"){
    keresztbe2+=1;
    i+=1;
   }
   else{h=false;}
}
i=1;h=true;
while ((temp+i*41)%40!=0 && h==true&& temp+i*41<1600){
    if(v[temp+i*41].szoveg=="X"){
        keresztbe2+=1;
        i+=1;
    }
    else{h=false;}
}
if (jobbra+balra>=5){
    jatek=false;
    kinyert="X nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (fel+le>=5){
    jatek=false;
    kinyert="X nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (keresztbe1>=5){
    jatek=false;
    kinyert="X nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (keresztbe2>=5){
    jatek=false;
    kinyert="X nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}



} // szoveg=="X" vizsgalatanak vege


else {
          unsigned int balra,jobbra,keresztbe1,keresztbe2,fel,le;
    balra=0;jobbra=0;keresztbe1=0;keresztbe2=0;fel=0;le=0;
    for ( int i=0;i<=temp%40;i++){
     if(v[temp-i].szoveg=="O" && temp-i>=0){
      balra+=1;
     }
     else{i=temp%40+1;}

    }

    for ( int i=1;temp%40+i<40;i++){
        if(v[temp+i].szoveg=="O" && temp+i<=1599){
            jobbra+=1;

        }
        else {i=41;}
    }

    for (int i=1;temp-i*40>=0;i++){
      if(v[temp-i*40].szoveg=="O"){
       fel+=1;

      }
      else {i=41;}
    }

    for (unsigned int i=0;i*40+temp<1600;i++){
      if(v[temp+i*40].szoveg=="O"){
       le+=1;
      }
      else {i=41;}
    }

    unsigned int i=0;bool h=true;
    while ((temp-i*39)%40!=0 && h==true && temp-i*39>=0){
        if(v[temp-i*39].szoveg=="O"){
            keresztbe1+=1;
            i+=1;
        }
        else {h=false;}
    }


    i=1;h=true;
    while ((temp+i*39)%40!=0 && h==true && temp+i*39<1560){ //javítani kell
      if(v[temp+i*39].szoveg=="O"){
        keresztbe1+=1;
    i+=1;
      }
      else {h=false;}
    }

//jobbrol balra pipa
i=0;h=true;
while ((temp-i*41)%40!=0 && h==true && temp-i*41>=0){
   if(v[temp-i*41].szoveg=="O"){
    keresztbe2+=1;
    i+=1;
   }
   else{h=false;}
}
i=1;h=true;
while ((temp+i*41)%40!=0 && h==true&& temp+i*41<1600){
    if(v[temp+i*41].szoveg=="O"){
        keresztbe2+=1;
        i+=1;
    }
    else{h=false;}
}
if (jobbra+balra>=5){
    jatek=false;
    kinyert="O nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (fel+le>=5){
    jatek=false;
    kinyert="O nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (keresztbe1>=5){
    jatek=false;
    kinyert="O nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}
if (keresztbe2>=5){
    jatek=false;
    kinyert="O nyert, restarthoz nyomj egy backspace-t (mert annak tudom fejbol a keycode-jat)";
}


}       // O vizsgálat vége
}


kattintx=0;
kattinty=0;
if (keyertek==8 && jatek==false){
    keyertek=0;
    jatek=true;
    for (unsigned int i=0;i<v.size();i++){
        v[i].szoveg="";
    }
}
};






void amoba:: focusfv(){};
