#ifndef SZAMOLOGEP_H
#define SZAMOLOGEP_H
#include <gomb.h>
#include <vector>
struct szamologep: public widget
{
      std::  vector <gomb> v;
      std:: string ertekir;
     long long vegrehajtas;
     std::string muvelet;
      bool pushback;

        szamologep(int a,int b);
        virtual ~szamologep();
    void focusfv();
    void dolgozik();
    void rajzol();
};

#endif // SZAMOLOGEP_H
