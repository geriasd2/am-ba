#ifndef SZAMBEALLITO_H
#define SZAMBEALLITO_H
#include <widget.h>
#include <string>


struct szambeallito : public widget {

       int szamertek,also,felso;
       std::string ertekir;


    szambeallito(int a,int b,int c,int d,int e);
        virtual ~szambeallito();
        void  rajzol();
        void focusfv();
        void dolgozik();

};

#endif // SZAMBEALLITO_H
