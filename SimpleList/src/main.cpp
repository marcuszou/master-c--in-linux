#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[]){
    List simpleList;
    Database data;

    if(arg_count > 1) {
        simpleList.name = string(args[1]);
        data.read();
        simpleList.print_menu();
    }
    else {
        cout << "Username not supplied.. exiting the program" << endl;
    }

    return 0;

}
