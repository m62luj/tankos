#include "GameMaster.h"
#include <sstream>
using namespace std;

void torol(){
    gout<<move_to(0,0)<<color(0, 0, 0)<<box(800,600);
    }


int str_to_int(string input)
{
    stringstream temp;
    temp << input;
    int temp_;
    temp >> temp_;
    return temp_;

}

string inti_to_string(int input)
{
    string temp_;
    stringstream temp;
    temp << input;
    temp >> temp_;
    return temp_;
}

void GameMaster::run()
{
    gout.open(800,600);
    gin.timer(0);

    gout << refresh;
    event ev;


    while(gin >> ev) {
        if(!game)
        {
            newGame(ev);
        }

        if(game)
        {
        torol();

        gout << move_to(600,0) << color(200,200,200)<<box(200,600);
        gout <<color(255,0,0);
        for(int i = 0; i<60; i++)
        {
            for(int j = 0; j < 60 ; j++)
            {
                if(  ((i-30)) * ((i-30)) + ((j-30)) * (j-30) - 30*30 <= 0)
                {
                    gout << move_to(670+i, 470+j) << dot;
                }
            }
        }
        gout << color(200,200,200);
        for(int i = 0; i<56; i++)
        {
            for(int j = 0; j < 56 ; j++)
            {
                if(  ((i-28)) * ((i-28)) + ((j-28)) * (j-28) - 28*28 <= 0)
                {
                    gout << move_to(672+i, 472+j) << dot;
                }
            }
        }

        gout << move_to(700,500) << color(255,0,0) << line(6*wind_x, -6*wind_y);


        for(unsigned i = 0; i<widgets.size(); i++)
        {



            if(!shooting)
            {
                if(player==1 && i<3)
                {
                    widgets[i]->eventHandler(ev);
                }
                if(player==2 && i>2 && i<6)
                {
                    widgets[i]->eventHandler(ev);
                }
                if(i==6)
                {
                    widgets[i]->eventHandler(ev);
                }

            }
            if(shooting && i==7)
            {
                widgets[7]->eventHandler(ev);
            }

            widgets[i]->draw();

        }
        {
        gout << color(150,150,150);
        gout << move_to(610,100-gout.cascent()) << text("PLAYER 1");
        gout << move_to(650,100+gout.cascent()+gout.cdescent()) << text("POWER");
        gout << move_to(650,140+gout.cascent()+gout.cdescent()) << text("ANGLE");
        gout << move_to(610,220-gout.cascent()) << text("PLAYER 2");
        gout << move_to(650,220+gout.cascent()+gout.cdescent()) << text("POWER");
        gout << move_to(650,260+gout.cascent()+gout.cdescent()) << text("ANGLE");
        gout << color(200,200,200) << move_to(widgets[(player-1)*3]->getX()+2,widgets[(player-1)*3]->getY()+2) << box(66,26);
        }



        tank1->changeValue(str_to_int(angle1->getValue()), str_to_int(power1->getValue()));
        tank2->changeValue(str_to_int(angle2->getValue()), str_to_int(power2->getValue()));

        gout << refresh;
        if(ev.type == ev_key && ev.keycode == key_enter && !shooting)
        {
            shooting = !shooting;
            if(player==1)
            {
                Projectile * proj = new Projectile(tank1->getX()+45,tank1->getY(),str_to_int(angle1->getValue()), str_to_int(power1->getValue()), wind_x, wind_y);
                widgets.push_back(proj);
            }
            if(player==2)
            {
                Projectile * proj = new Projectile(tank2->getX()+45,tank2->getY(),str_to_int(angle2->getValue()), str_to_int(power2->getValue()), wind_x, wind_y);
                widgets.push_back(proj);
            }

        }


        if((widgets.size())==8 && shooting)
        {

            for(unsigned i = 0; i<2; i++)
            {
                if( (widgets[7]->getX()-10 >= widgets[i*3]->getX()) && ( widgets[7]->getX() <= widgets[i*3]->getX()+70 ) && widgets[7]->getY()-10> widgets[i*3]->getY())
                {

                    gameOver();
                    shooting = false;




                }
            }
            if(widgets.size()==8)
            {
                if((widgets[7]->getY())>600 || widgets[7]->getX()<-100 || widgets[7]->getX()>700 || widgets[7]->getY() < -100)
            {
                for(unsigned i=0; i<widgets.size();i++)
            {
                widgets[i]->unfocus();
            }

            delete widgets[7];
            widgets[7]=nullptr;
            widgets.pop_back();
            shooting = !shooting;
            player++;
            wind_x = (rand()%14-7);
            wind_y = (rand()%14-7);


            if(player>2)
            {
                player=1;

            }
            }
            }


        }
        }




    }
}

void GameMaster::gameOver()
{

    torol();
    gin.timer(0);
    gout << move_to(5,45) << color(0,255,0) << text("GAME OVER");
    gout << refresh;
    game=false;

}

void GameMaster::newGame(event ev)
{

    gout << move_to(5,30) << color(0,255,0) << text("Press F1 to start New Game!")<<refresh;

    if(ev.type == ev_key && ev.keycode == key_f1)
    {
    ///change to default values!!!


    gin.timer(200);
    game = true;
    player = 1;
    wind_x = (rand()%14-7);
    wind_y = (rand()%14-7);

    shooting = false;
    if(widgets.size()==8)
    {
        delete widgets[7];
            widgets[7]=nullptr;
            widgets.pop_back();
    }
    }

}


void GameMaster::action()
{
    if(!shooting)
        {
            shooting = !shooting;
            if(player==1)
            {
                Projectile * proj = new Projectile(tank1->getX()+45,tank1->getY(),str_to_int(angle1->getValue()), str_to_int(power1->getValue()), wind_x, wind_y);
                widgets.push_back(proj);
            }
            if(player==2)
            {
                Projectile * proj = new Projectile(tank2->getX()+45,tank2->getY(),str_to_int(angle2->getValue()), str_to_int(power2->getValue()), wind_x, wind_y);
                widgets.push_back(proj);
            }

        }
}
