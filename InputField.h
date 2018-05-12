#ifndef INPUTFIELD_H
#define INPUTFIELD_H
#include <vector>

#include "MovableWidget.h"
using std::vector;
using std::string;
using genv::event;

class InputField : public MovableWidget
{
    protected:
            string content;

    public:
        InputField(int _x, int _y, int _meretx, int _merety):MovableWidget(_x, _y, _meretx, _merety){};
        ~InputField(){};
        //virtual void setText(string sText);
        //virtual void textin();
        virtual void draw();
        virtual void eventHandler(event ev);
        virtual void textIn(event ev);
        virtual string getValue();

    private:
};

#endif // INPUTFIELD_H
