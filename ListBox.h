#ifndef LISTBOX_H
#define LISTBOX_H
#include <iostream>
#include <vector>

#include "Widget.h"
using namespace std;
using namespace genv;


class ListBox : public Widget
{
    public:
        ListBox(int _x, int _y, int _meretx, int _merety, int _lista_meret_x, int _lista_meret_y, vector<string> _content):Widget(_x,_y, _meretx, _merety)
        {
            lista_meret_x = _lista_meret_x;
            lista_meret_y = _lista_meret_y;
            content = _content;
        };
        ListBox(int _x, int _y, int _meretx, int _merety):Widget(_x,_y, _meretx, _merety)
        {
            vector<string> _content;
            _content.push_back("elso");
            _content.push_back("masodik");
            _content.push_back("harmadik");
            for(int i = 0; i < 10; i++)
            {

                _content.push_back("placeholder");
            }

            content = _content;
        };
        ~ListBox(){};
        virtual void draw();
        virtual void eventHandler(event ev);
        bool open = false;
        virtual void kinyit(event ev);
        virtual void createCanvas();
        virtual void move_list(event ev);
        virtual void focus_element(event ev);
        virtual int listOver(event ev);
        virtual void draw_canvas();
        virtual void select_element(event ev);
        virtual void append(vector<string> appendix);
        virtual string getValue();
        virtual bool is_over_list(event ev);

    protected:
        int lista_meret_x = 150;
        int lista_meret_y = 200;
        int focused_element = 0;
        int lista_pos=0;
        int c_size_x=0;
        int c_size_y;
        int selected_element = -1;
        canvas c;
        vector<string> content;

        //virtual bool isOver_2(int px, int py);
};

#endif // LISTBOX_H
