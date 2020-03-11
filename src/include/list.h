#include<iostream>
#include<vector>
#include<stdio.h>
#include<ncurses.h>
using namespace std;


class List {
    private:
    
    protected:
    
    public:
    List(){

    }
    ~List(){

    }

    string name;
    vector<string> list;

    void print_menu(WINDOW* win,WINDOW* outputwin);
    void print_list(WINDOW* win,WINDOW* outputwin);
    void add_item(WINDOW* win,WINDOW* outputwin);
    void delete_item(WINDOW* win,WINDOW* outputwin);

};