#ifndef ADOGATOSMENU_H
#define ADOGATOSMENU_H
#include <widget.h>
#include <valasztos1.h>
#include <gepeles.h>
struct adogatosmenu : public widget
{
    valasztos1 v1,v2;
    gepeles g;
        adogatosmenu(int a,int b);
        virtual ~adogatosmenu();
    void rajzol();
    void dolgozik();
    void focusfv();
};

#endif // ADOGATOSMENU_H
