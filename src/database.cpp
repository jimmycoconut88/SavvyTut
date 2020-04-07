#include "include/database.h"

void Database::write(vector<vector<string>> mainList)
{
    ofstream db;
    db.open("db/lists.sl");

    if (db.is_open())
    {
        for (int user_index = 0; user_index < (int)mainList.size(); user_index++)
        {
            for (int list_index = 0; list_index < (int)mainList[user_index].size(); list_index++)
            {
                if (list_index == 0)
                {
                    db << "#" << mainList[user_index][list_index] << "\n";
                }
                else
                {
                    db << mainList[user_index][list_index] << "\n";
                }
            }
            db << "%"
               << "\n";
        }
    }
    else
        cout << "Can't opern file";
    db.close();
}

vector<vector<string>> Database::read()
{
    string line;
    ifstream db;
    vector<string> userlist;
    db.open("db/lists.sl");
    if (db.is_open())
    {
        while (getline(db, line, '\n'))
        {
            if (line.front() == '#')
            {

                line.erase(line.begin());
                userlist.push_back(line);
            }
            else if (line.front() == '%')
            {

                mainList.push_back(userlist);
                userlist.clear();
            }
            else
            {

                userlist.push_back(line);
            }
        }
    }
    else
    {
        cout << "Cannot open file.\n";
    }
    return mainList;
}