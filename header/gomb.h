#ifndef GOMB_H
#define GOMB_H
#include <widget.h>
#include <string>
struct gomb : public widget{
    std::string szoveg;
        gomb(int a,int b,int c, int d,std::string ss);
        virtual ~gomb();
         void focusfv();
         void dolgozik();
         void rajzol();




};

#endif // GOMB_H
