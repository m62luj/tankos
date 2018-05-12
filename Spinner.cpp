#include "Spinner.h"
#include "graphics.hpp"
#include <iostream>
#include <sstream>
using namespace std;
using namespace genv;






void Spinner::draw()
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

    if(value > max_value || value < min_value || meretx < 30 || merety < 20)
    {

        gout << move_to(x+3, y+gout.cascent()+gout.cdescent()) << color(255,0,0) << text("Incorrect starting value or size of Spinner");
    }else
    {


        gout << box(meretx+8, merety+8) << move_to(x, y) << color(250,250,250) << box(meretx-20, merety);
        gout << move_to(x+meretx-17, y) << box(17,merety/2-3) << move_to(x+meretx-11, y+(merety)/4) << color(255,0,0) << text('+');
        gout << color(250,250,250);
        gout << move_to(x+meretx-17, y+merety/2) << box(17,merety/2) << move_to(x+meretx-11, y+3*(merety)/4) << color(255,0,0) << text('-');
        gout << color(255,0,0) << move_to(x, y+(merety)/2) << text(int_to_string(value));

    }
}

void Spinner::eventHandler(event ev)
{
    focus(ev);
    changeValue(ev);
}

void Spinner::changeValue(event ev)
{
    int px = ev.pos_x;
    int py = ev.pos_y;
    if(selected)
    {
            if(ev.type == ev_mouse && ev.button == btn_left)
            {
                if(px > x+meretx-17 && px < x+meretx)
                {
                if(py > y && py < y+merety/2)
                {
                    if(value < max_value)
                    {
                        value++;
                    }
                }
                if(py > y+merety/2 && py<y+merety)
                {
                    if(value > min_value)
              {
                    value--;
              }
                }
                }
            }
            if(ev.keycode == key_up || ev.keycode == key_pgup)
            {
              if(value < max_value)
              {
                  value++;
              }
            }
            if(ev.keycode == key_down || ev.keycode == key_pgdn)
            {
              if(value > min_value)
              {
                  value--;

              }
            }
    }
}

string Spinner::getValue()
{
    string temp;

    temp = int_to_string(value);

    return temp;
}


