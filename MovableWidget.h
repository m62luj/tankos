#ifndef MOVABLEWIDGET_H
#define MOVABLEWIDGET_H

#include "Widget.h"
using genv::event;

class MovableWidget : public Widget
{
private:
    int dx=0;
    int dy=0;
    bool clicked = false;

public:
        MovableWidget(int _x, int _y, int _meretx, int _merety):Widget(_x, _y, _meretx, _merety){};
        ~MovableWidget(){};
        virtual void mozgat(event ev);
        virtual void eventHandler(event ev)=0;
        virtual void draw()=0;
};

#endif // MOVABLEWIDGET_H
