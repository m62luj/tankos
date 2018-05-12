#ifndef SIMPLETEXT_H
#define SIMPLETEXT_H
#include "Widget.h"
#include <iostream>
#include "graphics.hpp"
using std::string;
using namespace genv;
class SimpleText : public Widget
{
    protected:
    string content;

    public:
        SimpleText(int _x, int _y, string _content):Widget(_x, _y)
        {content = _content;
        meretx = gout.twidth(_content);
        merety = gout.cascent()+gout.cdescent();
        };
        ~SimpleText(){};
        //virtual void setText(string sText);
        virtual void draw();
        void eventHandler(event ev)
        {
            focus(ev);
        };

};
#endif // SIMPLETEXT_H
