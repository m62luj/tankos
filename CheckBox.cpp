#include "CheckBox.h"
#include "graphics.hpp"
#include <iostream>
using std::cout;
using std::endl;
using namespace genv;
void CheckBox::draw()
{
    gout << move_to(x,y);
    if(selected)
    {
        gout << color(100,100,100);
    }
    if(!selected)
    {
        gout << color(200,200,200);
    }
    gout << box(meretx, merety) << move_to(x+2, y+2) <<  color(250,250,250) << box(meretx-4, merety-4);
    if(state)
    {
        gout << move_to(x+5, y+5) << color(0,0,0)<<line(meretx-10,merety-10) << move_to(x+5, y+merety-5) << line_to(x+meretx-5, y+5);
    }
}

void CheckBox::eventHandler(event ev)
{
    check(ev);
    mozgat(ev);
    focus(ev);
}

void CheckBox::check(event ev)
{
    if(ev.type == ev_mouse && ev.button ==  btn_right && isOver(ev.pos_x,ev.pos_y))
    {
        state = !state;
        cout << state << endl;
    }
}
