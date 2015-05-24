#ifndef WIDGET_H
#define WIDGET_H


struct widget{
   double x,y,szelesseg,hossz,kattintx,kattinty;
unsigned int keyertek;
bool mukodj,focus;
        widget(int a,int b,int c, int d);
        virtual ~widget();
virtual void dolgozik();
virtual void rajzol();
virtual void focusfv();
};

#endif // WIDGET_H
