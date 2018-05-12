#ifndef TANK_H
#define TANK_H
#include "graphics.hpp"
#include "Widget.h"
#include <iostream>
using genv::event;
using std::string;

class Tank : public Widget
{
    public:
        Tank(int _x, int _y, int _meretx, int _merety):Widget(_x, _y, _meretx, _merety)
        {

        };
        ~Tank(){} ;
        virtual void draw();
        virtual void eventHandler(event ev);
        virtual string getValue();
        virtual void changeValue(int _ang, int _powerr);

    protected:
        int angle;
        int powerr;
    private:
};

#endif // TANK_H
