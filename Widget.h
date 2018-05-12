#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <sstream>
using genv::event;
using std::string;
using std::vector;
using std::stringstream;

class Widget
{



    protected:
    int x;
    int y;
    int meretx;
    int merety;
    bool selected = false;
    bool isOver(int px, int py);

    public:
    Widget(int _x, int _y, int _meretx, int _merety);
    Widget(int _x, int _y);
    virtual ~Widget(){};
    virtual void draw()=0;
    virtual void focus(event ev);
    void unfocus(){selected = false;};
    virtual void eventHandler(event ev)=0;
    void setSelected(bool kaki){selected = kaki;};
    bool getSelected(){return selected;};
    virtual string getValue()=0;
    virtual void append(vector<string> appendix){};
    string int_to_string(int input)
    {
    string temp_;
    stringstream temp;
    temp << input;
    temp >> temp_;
    return temp_;
    }
    virtual float rad(int in);
    int getY()
    {
            return y;
    }
    int getX()
    {
        return x;
    }

};


#endif // WIDGET_H
