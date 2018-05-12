#include "ListBox.h"
#include "graphics.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace genv;

void ListBox::draw()
{
    gout << move_to(x-4,y-4);
    if(selected)
    {
        gout << color(100,100,100);
    }
    if(!selected)
    {
        gout << color(200,200,200);
    }
    gout << box(meretx+8, merety+8) << move_to(x, y) << color(250,250,250) << box(meretx-20, merety);

    if(!open)
    {


        gout << move_to(x+meretx-17, y) << box(17,merety) << move_to(x+meretx-11, y+(merety)/2) << color(255,0,0) << text('v');


    }
    if(open)
    {
        draw_canvas();
        gout << move_to(x+meretx-17, y) << box(17,merety) << move_to(x+meretx-11, y+(merety)/2) << color(255,0,0) << text('^');
        gout << stamp(c,0,lista_pos, lista_meret_x, lista_meret_y, x, y+merety);
    }
    if(selected_element>-1)
    {


        gout << move_to(x,y+gout.cascent()) << color(200,200,200) << text(content[selected_element]);

    }
}

void ListBox::kinyit(event ev)
{
                if(ev.type == ev_mouse && ev.button == btn_left)
                {
                    if(ev.pos_x > x+meretx - 17 && ev.pos_x < x+meretx && ev.pos_y > y && ev.pos_y < y+merety)
                    {


                        cout << open;
                        open = !open;

                        if(open)
                        {
                            createCanvas();
                        }
                    }

                }


}

void ListBox::createCanvas()
{

    c_size_y = (gout.cascent()+gout.cdescent())*content.size()+gout.cdescent();
    for(int i = 0; i<content.size(); i++)
    {
        if(c_size_x<gout.twidth(content[i]))
        {
            c_size_x=gout.twidth(content[i]);
        }
    }
    if(lista_meret_x > c_size_x)
    {
        c_size_x = lista_meret_x;
    }
    if(lista_meret_y > c_size_y)
    {
        c_size_y = lista_meret_y;
    }
    c.open(c_size_x, c_size_y);
}

void ListBox::move_list(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_wheeldown)
    {
      lista_pos=lista_pos+3;
      if(lista_pos>(gout.cascent()+gout.cdescent())*content.size()+gout.cdescent()-lista_meret_y)
      {
          lista_pos=(gout.cascent()+gout.cdescent())*content.size()+gout.cdescent()-lista_meret_y;
      }
    }
    if(ev.type == ev_mouse && ev.button == btn_wheelup)
    {
      lista_pos=lista_pos-3;
      if(lista_pos<0)
      {
          lista_pos=0;
      }
    }
}

void ListBox::focus_element(event ev)
{
    /*if(open)
    {
        c<<move_to(0,listOver(ev)*(gout.cascent()+gout.cdescent())) << color(255,0,0) << box(lista_meret_x,gout.cascent()+gout.cdescent());
    }*/
    if(open&&ev.type == ev_mouse)
    {

    focused_element = listOver(ev);
    //cout << focused_element;
    }
    if(ev.keycode == key_up || ev.keycode == key_pgup)
            {

              if(focused_element > 0)
              {
                  focused_element--;
              }
            }
    if(ev.keycode == key_down || ev.keycode == key_pgdn)
            {
              if(focused_element < content.size())
              {
                  focused_element++;
              }
            }
}

int ListBox::listOver(event ev)
{
    for(int i=0; i<content.size(); i++)
    {
        if(ev.pos_x<x+lista_meret_x && ev.pos_x>x && ev.pos_y > y+merety && ev.pos_y < y+merety+lista_meret_y && ev.type == ev_mouse)
        {
            if(ev.pos_y > y+merety-lista_pos+i*(gout.cascent()+gout.cdescent()) && ev.pos_y < y+merety- lista_pos + (i+1)*(gout.cascent()+gout.cdescent())  )
            {

                return i;
            }

        }
    }

}

void ListBox::draw_canvas()
{
    c<<move_to(0,0)<< color(250,250,250) << box(c_size_x,c_size_y) << color(0,0,0);
    for(int i = 0; i<content.size(); i++)
        {
            if(i!=focused_element)
            {
            c << color(100,100,100);
            }
            else{c << color(200,200,200);}
            /*if(i=focused_element)
            {

            }*/
            c<< move_to(0,(gout.cascent()+gout.cdescent())*(i+1)-gout.cdescent()) << text(content[i]);
        }
}
void ListBox::select_element(event ev)
{
    if( (ev.type == ev_mouse && ev.button == btn_left && ev.pos_x > x && ev.pos_x<x+lista_meret_x && ev.pos_y > y+merety && ev.pos_y < y+merety+lista_meret_y) || (ev.type == ev_key && ev.keycode == key_enter) )
    {
        selected_element = focused_element;
        open = false;

    }
}


void ListBox::eventHandler(event ev)
{

    focus(ev);
    if(isOver(ev.pos_x,ev.pos_y) || is_over_list(ev))
    {
        focus_element(ev);
        select_element(ev);
        kinyit(ev);
        move_list(ev);
    }





}

void ListBox::append(vector<string> appendix)
{
    for(int i=0; i<appendix.size(); i++)
    {
        content.push_back(appendix[i]);
    }
    createCanvas();
}


string ListBox::getValue()
{
    if(selected_element > -1)
    {
    string temp;
    temp = content[selected_element];

    return temp;
    }
    if(selected_element==-1)
    {
        string temp;
        temp = "No selected element";
        return temp;
    }
}

bool ListBox::is_over_list(event ev)
{
    if(ev.pos_x > x && ev.pos_x < x+lista_meret_x && ev.pos_y > y+merety && ev.pos_y<y+merety+lista_meret_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
