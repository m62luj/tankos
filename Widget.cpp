#include "Widget.h"
#include <iostream>
#include "graphics.hpp"
using namespace std;
using namespace genv;

Widget::Widget(int _x, int _y, int _meretx, int _merety)
{
    x=_x;
    y=_y;
    meretx=_meretx;
    merety=_merety;
}
Widget::Widget(int _x, int _y)
{
    x=_x;
    y=_y;
}

/*Widget::~Widget()
{
    delete this;
}*/

bool Widget::isOver(int px, int py)
{
    if(px<x || px >x+meretx || py<y || py>y+merety)
    {

        return false;
    }else
    {

        return true;
    }
}

void Widget::focus(event ev)
{
    int px = ev.pos_x;
    int py = ev.pos_y;
    bool kaki = isOver(px,py);
    if(ev.type == ev_mouse && ev.button == btn_left && kaki)
    {

        selected = true;

    }
    if(ev.type == ev_mouse && ev.button == btn_left && !kaki)
    {
        selected = false;
        //return nullptr;
    }

}

float Widget::rad(int in)
{
    float out;
    out = in*3.1415/180;
    return out;
}
