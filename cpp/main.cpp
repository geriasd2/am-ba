
#include <graphics.hpp>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <sstream>
#include <sztring.h>
#include <widget.h>
#include <szambeallito.h>
#include <valasztos1.h>
#include <gui.h>
#include <gomb.h>
#include <szamologep.h>
#include <gepeles.h>
#include <aknakereso.h>
#include <time.h>
using namespace genv;
using namespace std;

int main (){
    srand(time(0));

    unsigned int c=1600;
unsigned int d=900;
gui esemeny(c,d);

  {
    szambeallito *sz=new szambeallito(500,500,0,20,10);
   esemeny.pushback(sz);
  }
vector <sztring> monika;
sztring k;
for (unsigned int i=0;i<20;i++){


k.szoveg="lel";k.mutat=false;
monika.push_back(k);
k.szoveg="lasldlasd";k.mutat=false;
monika.push_back(k);
k.szoveg="ladiughdilag";k.mutat=false;
monika.push_back(k);
}
{
    valasztos1 *sz=new valasztos1(100,100,monika);
    esemeny.pushback(sz);
}

{
    szamologep *sz=new szamologep(300,500);
    esemeny.pushback(sz);
}
{
  //  gepeles *sz=new gepeles (500,100);
  //  esemeny.pushback(sz);
}
{
    aknakereso *sz=new aknakereso (400,50);
    esemeny.pushback(sz);
}




esemeny.esemeny(1);



return 0;
}

