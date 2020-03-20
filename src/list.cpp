#include "include/list.h"

void List::print_menu(WINDOW *win, WINDOW *outputwin)
{
    int choice, highlight = 0;
    keypad(win, true); // help to identify KEY_UP or KEY_F
    wclear(win);
    box(win, 0, 0);
    box(outputwin, 0, 0);
    string choices[4] = {"1 - Print List", "2 - Add to List", "3 - Delete from List", "4 - Quit"};

    //mvwprintw(win,6,1," Enter your choice and press return: ");
    wrefresh(win);
    wrefresh(outputwin);
    while (1)
    { // This while loop means that every loop it print out all option with one thats highlighted
        //
        for (int i = 0; i < 4; i++)
        { //Print out all option normally except highlight the one needed
            if (i == highlight)
                wattron(win, A_REVERSE);
            mvwprintw(win, i + 1, 1, choices[i].c_str());
            wclear(outputwin);
            box(outputwin, 0, 0);
            mvwprintw(outputwin, 1, 1, "You Choice: %s", choices[highlight].c_str());
            wrefresh(outputwin);
            wattroff(win, A_REVERSE);
        }
        choice = wgetch(win); //Current cursor position

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 4)
                highlight = 3;
            break;
        default:
            break;
        }
        if (choice == 10) //10 == pressing enter
            break;
    }
    switch (highlight)
    {
    case 0:
        print_list(win, outputwin);
        break;
    case 1:
        add_item(win, outputwin);
        break;
    case 2:
        delete_item(win, outputwin);
        break;
    default:
        return;
    }
}

void List::add_item(WINDOW *win, WINDOW *outputwin)
{
    wclear(win);
    wclear(outputwin);
    box(win, 0, 0);
    box(outputwin, 0, 0);
    mvwprintw(outputwin, 1, 1, "*****Add Item*****");
    mvwprintw(outputwin, 2, 1, "Type in an item and press enter: ");
    wrefresh(outputwin);

    char item[50] = {};
    wgetstr(outputwin, item);
    list.push_back(item);
    wprintw(win, "Successfully added item to list \n\n\n\n\n");
    cin.clear();
    print_menu(win, outputwin);
}
void List::delete_item(WINDOW *win, WINDOW *outputwin)
{
    keypad(win, true);
    wclear(win);
    wclear(outputwin);
    box(win, 0, 0);
    box(outputwin, 0, 0);
    mvwprintw(outputwin, 1, 1, "*****Delete Item*****");

    mvwprintw(win, 1, 1, "**** Delete Item ****");
    mvwprintw(win, 2, 1, "Select an item index number to delete");
    int choiceNum, highlight = 0;
    if (list.size())
    {
        while (1)
        {
            // wrefresh(win);
            wrefresh(outputwin);
            for (int i = 0; i < (int)list.size(); i++)
            {
                if (i == highlight)
                    wattron(win, A_REVERSE);
                mvwprintw(win, i + 3, 1, list[i].c_str());
                wattroff(win, A_REVERSE);
            }
            choiceNum = wgetch(win);
            mvwprintw(outputwin, 2, 1, "                                   ");
            wrefresh(outputwin);
            switch (choiceNum)
            {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == (int)list.size())
                    highlight = (int)list.size() - 1;
                break;
            default:
                break;
            }
            if (choiceNum == 10)
                break;
            mvwprintw(outputwin, 2, 1, "Delete item: %s ", list[highlight].c_str());
        }
        list.erase(list.begin() + highlight);
    }
    else
    {
        wprintw(win, "No items to delete.\n");
    }
    print_menu(win, outputwin);
}

void List::print_list(WINDOW *win, WINDOW *outputwin)
{
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "**** Printing List ****");
    for (int list_index = 0; list_index < (int)list.size(); list_index++)
    {
        mvwprintw(win, list_index + 2, 1, "* %s", list[list_index].c_str());
    }
    //wprintw(win,"M - Menu \n");
    wrefresh(win);
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm')
        print_menu(win, outputwin);
    else
        wprintw(win, "Invalid Choice. Quitting..\n");
}

void List::find_userList(WINDOW *win, WINDOW *outputwin)
{
    bool userFind = false;
    wclear(outputwin);
    box(outputwin, 0, 0);
    mvwprintw(outputwin, 1, 1, "*****Welcome %s ****", name.c_str());

    for (int user_index = 0; user_index < (int)mainList.size(); user_index++)
    {
        //mvwprintw(win, user_index + 2, 1, "%s", mainList[user_index][0].c_str());
        //cout << mainList[user_index][0] << "\n";
        if (mainList[user_index][0] == name)
        {
            mvwprintw(outputwin, 2, 1, "User has been found: %s", mainList[user_index][0].c_str());
            //cout << " user has been found: " << mainList[user_index][0] << "\n";
            list = mainList[user_index];
            userFind = true;
            break;
        }
        else
        {
            mvwprintw(outputwin, 2, 1, "Welcome new User");
        }
    }
    mvwprintw(win, 1, 1, "Press Enter to Continue");
    wrefresh(outputwin);
    wrefresh(win);
    getch();
}