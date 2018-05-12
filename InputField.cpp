#include "InputField.h"
#include <iostream>
using namespace genv;
using namespace std;


void InputField::eventHandler(event ev)
{

    textIn(ev);
    mozgat(ev);
    focus(ev);
}



void InputField::draw()
{
//    int cursorpos=;
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
    if(gout.twidth(content) < meretx)
    {
    gout << color(0,0,0) << move_to(x, y+gout.cascent())<<text(content);
    }
    else
    {
        string temp;
        for(int i = 0; i<content.size(); i++)
        {
            if(gout.twidth(content.substr(i,content.size()))<meretx)
            {
                temp = content.substr(i,content.size());
                break;
            }

        }
        gout << color(0,0,0) << move_to(x, y+gout.cascent())<<text(temp);
    }

    if(selected)
    {
        gout << text("|");
    }

}

void InputField::textIn(event ev)
{
    if(selected)
        {
    int input = ev.keycode;
    if(ev.type == ev_key)
    {
        if (key_space <= ev.keycode && ev.keycode <= 255)
    {
            //if(gout.twidth(content)<meretx)
            {
            content.push_back(input);

            }

    }
    if (ev.keycode == key_backspace)
    {
            if(content.size()>0)
            {

            content.pop_back();
            }
            //cout << content << endl;
    }
    }
        }
}


string InputField::getValue()
{
    return content;
}
