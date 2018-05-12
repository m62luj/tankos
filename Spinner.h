#ifndef SPINNER_H
#define SPINNER_H
#include <iostream>
#include <sstream>
#include "Widget.h"


class Spinner : public Widget
{
    public:
    Spinner(int _x, int _y, int _meretx, int _merety, int _value, int _min_value, int _max_value):Widget(_x,_y, _meretx, _merety)
    {
        value = _value;
        min_value = _min_value;
        max_value = _max_value;
    };
    Spinner(int _x, int _y, int _meretx, int _merety, int _value):Widget(_x,_y, _meretx, _merety)
    {
        value = _value;
        min_value = 0;
        max_value = 100;
    };
    ~Spinner(){};
    virtual void draw();
    virtual void eventHandler(event ev);
    virtual void changeValue(event ev);
    virtual string getValue();
    //virtual void writeToLog(ofstream & output);
    protected:
        int value;
        int min_value, max_value;

};

#endif // SPINNER_H
