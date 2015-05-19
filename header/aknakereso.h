#ifndef AKNAKERESO_H
#define AKNAKERESO_H
#include <widget.h>
#include <gomb.h>
#include <vector>

struct  aknakereso : public widget{
   std:: vector <gomb> v;
   std:: vector <int> v1;
   bool jatek;
        aknakereso(int a,int b);
        virtual ~aknakereso();
        void rajzol();
        void focusfv();
        void dolgozik();

};

#endif // AKNAKERESO_H
