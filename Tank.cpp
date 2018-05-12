#include "Tank.h"
#include <cmath>
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using std::string;
using std::cout;


void Tank::draw()
{
    gout << move_to(x,y) << color(100,100,100) << box(meretx,merety);
    gout << move_to(x+meretx/2, y) << line(powerr*cos(rad(angle)), -powerr*sin(rad(angle)));
}

void Tank::eventHandler(event ev)
{

}

string Tank::getValue()
{
    string temp = int_to_string(angle);
            temp+= ";";
            temp+= int_to_string(powerr);
            return temp ;
}

void Tank::changeValue(int _ang, int _powerr)
{
    angle = _ang;
    powerr = _powerr;
}



