#ifndef FUNCTORBUTTON_H
#define FUNCTORBUTTON_H
#include <functional>
#include "Button.h"
#include "graphics.hpp"
using namespace genv;

class FunctorButton : public Button
{
    public:
        FunctorButton(int _x, int _y, int _meretx, int _merety, std::string _name, std::function<void()> _funct):Button(_x, _y, _meretx, _merety,_name), funct(_funct){};
        ~FunctorButton(){};
        void action()
        {
            funct();
        }
        virtual void eventHandler(event ev);
        virtual void clicked(event ev);

    protected:
        std::function<void()> funct;

    private:
};

#endif // FUNCTORBUTTON_H
