#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "graphics.hpp"
#include "MovableWidget.h"
using genv::event;

class CheckBox : public MovableWidget
{
    public:
        CheckBox(int _x, int _y, bool _state):MovableWidget(_x, _y, 20, 20){state = _state;};
        CheckBox(int _x, int _y):MovableWidget(_x, _y, 20, 20){};
        ~CheckBox(){};
        virtual void draw();
        virtual void eventHandler(event ev);
        virtual void check(event ev);
    protected:

    private:
        bool state = false;

};

#endif // CHECKBOX_H
