#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[])
{

    List simplelist;
    Database data;
    if (arg_count > 1)
    {
        //string name(args[1]);
        initscr();
        cbreak();
        int ymax, xmax;
        getmaxyx(stdscr, ymax, xmax); //get height/width of specified window (3 param)

        //Create window for input
        WINDOW *outputwin = newwin(4, xmax - 12, ymax - ymax + 1, 5);
        box(outputwin, 0, 0);
        //WINDOW *newwin(int nlines, int ncols, int begin_y, int begin_x);
        simplelist.name = string(args[1]);
        simplelist.mainList = data.read();

        WINDOW *win = newwin(20, xmax - 12, ymax - ymax + 5, 5);
        box(win, 0, 0);
        refresh();
        wrefresh(win);
        wrefresh(outputwin);
        simplelist.find_userList(win, outputwin);
        simplelist.print_menu(win, outputwin);
        wrefresh(win);
        data.write(simplelist.mainList);

        endwin();
    }
    else
        cout << "username not supplied....exiting";

    return 0;
}
