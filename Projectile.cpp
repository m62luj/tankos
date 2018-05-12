#include "Projectile.h"
#include "graphics.hpp"
#include "Widget.h"
#include <iostream>
using namespace genv;
using std::string;
using std::vector;




void Projectile::eventHandler(event ev)
{
    mozgat(ev);
}

void Projectile::draw()
{
 gout << color(255,0,0) << move_to(x,y) << box(meretx,merety);
 for(unsigned i=1; i<path.size();i++)
 {
     gout << move_to(path[i-1].x,path[i-1].y) << line_to(path[i].x,path[i].y);
 }
}

void Projectile::mozgat(event ev)
{

    if(ev.type == ev_timer)
    {
        x=x0+powerr*cos(rad(angle))*t+wind_x*t*t/2;
        y=y0-powerr*sin(rad(angle))*t +(10-wind_y)/2*t*t;
        t++;
        koord k;
        k.x = x;
        k.y = y;
        path.push_back(k);
    }
}

string Projectile::getValue()
{

}
