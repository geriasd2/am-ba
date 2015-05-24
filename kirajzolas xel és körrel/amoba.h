#ifndef AMOBA_H
#define AMOBA_H
#include <widget.h>
#include <vector>
#include <gomb.h>
struct amoba: public widget
{       unsigned int hanyadik;
        bool jatek;
        std::vector<gomb> v;
        amoba(int a, int b);
        virtual ~amoba();
        void dolgozik();
        void focusfv();
        void rajzol();

};

#endif // AMOBA_H
