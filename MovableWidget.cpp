#include "MovableWidget.h"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;
void MovableWidget::mozgat(event ev)
{
        int px=ev.pos_x;
        int py=ev.pos_y;

if(ev.type!=ev_timer)
{
  if(ev.type == ev_mouse && ev.button == btn_left && isOver(px,py))
    {
        dx=px-x;
        dy=py-y;

        clicked = true;
        selected = true;
        //cout << clicked;

    }
    if(ev.type == ev_mouse && ev.button == -btn_left &&  isOver(px,py))
    {

        clicked = false;
        //cout << clicked;
        dx=0;
        dy=0;
    }


if(clicked)
    {
    x = px-dx;
    y = py-dy;
    }
}

}



