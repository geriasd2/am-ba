#ifndef VALASZTOS1_H
#define VALASZTOS1_H
#include <widget.h>
#include <sztring.h>
#include <vector>


struct valasztos1 : public widget
{
 vector<sztring> v;
 unsigned int ertek,igazit,pozi,allando;
        valasztos1(int a,int b, vector<sztring> s);
        virtual ~valasztos1();
        void rajzol();
        void dolgozik();
        void focusfv();

};

#endif // VALASZTOS1_H
