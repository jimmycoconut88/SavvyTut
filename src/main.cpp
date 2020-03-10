#include"include/list.h"
#include "include/database.h"


int main(int arg_count, char *args[]){
    List simplelist;
    Database data;
    if(arg_count > 1){
        //string name(args[1]);
        
       simplelist.name = string (args[1]);
        simplelist.print_menu();
        data.write(simplelist.list);
        data.read();
    }
    else cout<< "username not supplied....exiting";
 

    return 0;
}

