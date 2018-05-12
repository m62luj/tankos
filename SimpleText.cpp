#include "SimpleText.h"
#include "graphics.hpp"
using namespace genv;
using std::string;

/*SimpleText::SimpleText(int _x, int _y, string sText):Widget(_x,_y)
            {
            //content = sText;

            };*/
void SimpleText::draw()
{
    gout << move_to(x-4,y-4);
    if(selected)
    {
        gout << color(100,100,100);
    }
    if(!selected)
    {
        gout << color(200,200,200);
    }
    gout << box(meretx+8, merety+8) << move_to(x, y) << color(250,250,250) << box(meretx, merety);
    gout << color(0,0,0) << move_to(x, y+gout.cascent()) << color(0,0,0)<<text(content);
}


