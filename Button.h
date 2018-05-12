#ifndef BUTTON_H
#define BUTTON_H
#include <graphics.hpp>

#include "Widget.h"
using genv::event;

class Button : public Widget
{
    public:
        Button(int _x, int _y, int _meretx, int _merety, string _name):Widget(_x, _y, _meretx,_merety){content = _name;};
        virtual ~Button(){};
        virtual void draw();
        virtual void eventHandler(event ev)=0;
        std::string getValue()
        {
            return content;
        };

    protected:


    private:
        virtual void action()=0;
        std::string content="str";


};

#endif // BUTTON_H
