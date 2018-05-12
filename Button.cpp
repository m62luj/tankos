#include "Button.h"
#include <graphics.hpp>
using namespace genv;


void Button::draw()
{
    gout << move_to(x,y) << color(100,100,100) <<box(meretx, merety) << genv::move_to(x,y+merety/2) << color(255,0,0) << text(content);
}
