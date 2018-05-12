#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "graphics.hpp"
#include "Widget.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace genv;
using std::string;
using std::vector;

struct koord
{
    int x;
    int y;
};

class Projectile : public Widget
{
    public:
        Projectile(int _x, int _y, int _angle, int _powerr, int _wind_x, int _wind_y):Widget(_x,_y)
        {
            meretx = 10;
            merety = 10;
            angle = _angle;
            powerr = _powerr;
            wind_x = _wind_x;
            wind_y = _wind_y;


        };
        ~Projectile(){};
        virtual void eventHandler(event ev);
        virtual void draw();
        virtual void mozgat(event ev);
        virtual string getValue();

    protected:
    private:
        float angle;
        float powerr;
        float t=0;
        float x0=x;
        float y0=y;
        int wind_x;
        int wind_y;
        vector<koord> path;

};

#endif // PROJECTILE_H
