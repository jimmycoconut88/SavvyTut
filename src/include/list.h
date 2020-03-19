#include <iostream>
#include <vector>
using namespace std;

class List
{
private:
protected:
public:
    List()
    {
    }
    ~List()
    {
    }
    vector<vector<string>> mainList;
    string name;
    vector<string> list;

    void print_menu();
    void print_list();
    void add_item();
    void delete_item();
    void find_userList();
};