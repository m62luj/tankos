#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include "Widget.h"
#include "Tank.h"
#include "Projectile.h"
#include "Spinner.h"
#include "graphics.hpp"
#include "Button.h"
#include "FunctorButton.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
using namespace genv;
class GameMaster
{
    public:
        GameMaster()
        {
            power1 = new Spinner(610,100,180,30,68,0,100);
            angle1 = new Spinner(610,140,180,30,45,0,105);
            tank1 = new Tank(10,570,70,30);
            power2 = new Spinner(610,220,180,30,68,0,100);
            angle2 = new Spinner(610,260,180,30,135,75,180);
            tank2 = new Tank(520,570,70,30);
            button = new FunctorButton(610,320,180,30,"Shoot!", [this](){this->action();});
            widgets.push_back(tank1);
            widgets.push_back(power1);
            widgets.push_back(angle1);
            widgets.push_back(tank2);
            widgets.push_back(power2);
            widgets.push_back(angle2);
            widgets.push_back(button);

            wind_x = (rand()%14-7);
            wind_y = (rand()%14-7);
        };
        ~GameMaster()
        {
            delete power1;
            delete angle1;
            delete tank1;
            delete power2;
            delete angle2;
            delete tank2;
            delete button;
    for(int i = widgets.size(); i>-1;i--)
    {
        delete widgets[i];
        widgets.pop_back();

    }
        };
        virtual void run();
        virtual void newGame(event ev);
        virtual void gameOver();
        virtual void action();

    protected:
        bool game = 0;
        int player = 2;
        bool shooting = 0;
        Spinner * power1;
        Spinner * angle1;
        Tank * tank1;
        Spinner * power2;
        Spinner * angle2;
        Tank * tank2;
        FunctorButton * button;
        vector<Widget*> widgets;
        float wind_x;
        float wind_y;

    private:


};

#endif // GAMEMASTER_H
