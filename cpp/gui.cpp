#include "gui.h"


void gui::pushback(widget* w){
v.push_back(w);
}

gui::gui(unsigned int a,unsigned int b){
X=a;Y=b;
}
void gui::torol(){
    genv::gout<<genv::move_to(0,0)<<genv::color(255,255,255)<<genv::box(X-1,Y-1);


}
void gui::esemeny(unsigned int a){



genv:: gout.open(X,Y);
genv::gin.timer(a);
while(genv::gin>>ev && ev.keycode!=genv::key_escape){
        if (ev.type==genv::ev_timer){

torol();
 for (unsigned int i=0;i<v.size();i++){
  v[i]->rajzol();
  v[i]->dolgozik();
  v[i]->focusfv();
 }

genv::gout<<genv::refresh;
        }
        if (ev.button==genv::btn_left){
                for (unsigned int i=0;i<v.size();i++){
                    v[i]->kattintx=ev.pos_x;v[i]->kattinty=ev.pos_y;

                }



        }

      if ((ev.keycode>=31 && ev.keycode<=255) || ev.keycode==8){
        for (unsigned int i=0;i<v.size();i++){
                if (v[i]->focus==true){
            v[i]->keyertek=ev.keycode;}

        }
      }
      if (ev.button==genv::btn_wheeldown){
        for (unsigned int i=0;i<v.size();i++){
            v[i]->keyertek=ev.button;
        }

      }
      if (ev.button==genv::btn_wheelup){
        for (unsigned int i=0;i<v.size();i++){
            v[i]->keyertek=ev.button;
        }

      }



}







}
void gui::ujvektoradas(std::vector<widget*>&v1){
v=v1;
}
