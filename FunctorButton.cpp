#include "FunctorButton.h"
#include <graphics.hpp>

using namespace genv;

void FunctorButton::eventHandler(event ev)
{
    clicked(ev);
}

void FunctorButton::clicked(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left && isOver(ev.pos_x, ev.pos_y))
    {
        action();
    }
}
