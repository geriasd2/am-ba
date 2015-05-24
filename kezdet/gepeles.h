#ifndef GEPELES_H
#define GEPELES_H
#include <widget.h>
#include <string>

struct gepeles : public widget
{
        std::string szovegkiir;
        gepeles(int a,int b);
        virtual ~gepeles();
        void rajzol();
        void dolgozik();
        void focusfv();

};

#endif // GEPELES_H
