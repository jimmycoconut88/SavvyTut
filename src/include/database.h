#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


class Database {
    private:
    
    protected:
    
    public:
    Database(){

    }
    ~Database(){

    }

    string name;
    vector<string> list;

    void write(vector<string>list);
    void read();

};