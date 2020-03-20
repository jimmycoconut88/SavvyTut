#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Database
{
private:
protected:
public:
    Database()
    {
    }
    ~Database()
    {
    }

    string name;
    vector<vector<string>> mainList;

    void write(vector<vector<string>> mainList);
    vector<vector<string>> read();
};