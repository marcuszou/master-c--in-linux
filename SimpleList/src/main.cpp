#include <iostream>
#include <vector>
using namespace std;

void print_menu(string name);
void print_list();
void add_item();
void delete_item();

vector<string> list;
string name;

int main(int arg_count, char *args[]){

    if(arg_count > 1) {
        name = string(args[1]);
        print_menu(name);
    }
    else {
        cout << "Username not supplied.. exiting the program" << endl;
    }

    return 0;

}

void print_menu(string name){
    int choice;

    cout << "***************\n";
    cout << " 1 - Print list.\n";
    cout << " 2 - Add to list.\n";
    cout << " 3 - Delete from list.\n";
    cout << " 4 - Quit.\n";
    cout << " Enter your choice and press return/enter.\n";

    cin >> choice;

    if(choice == 4 ) {
        exit(0);
    }
    else if(choice == 3 ){
        delete_item();
    }
    else if(choice == 2 ){
        add_item();
    }
    else if(choice == 1 ) {
        print_list();
    }
    else {
        cout << "Sorry choice hasn't been implemented.\n";
    }
}

void add_item(){

    cout << "\n\n\n\n\n";
    cout << "*** Add Item ***";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n\n\n\n";
    cin.clear();

    print_menu(name);
}

void delete_item(){
    
    cout << "*** Delete Item ***\n";
    cout << "Select an item index to delete\n";

    if(list.size() > 0) {
        for(int i=0; i< list.size(); i++){
            cout << i << ": " << list[i] << "\n";
        }
    }
    else {
        cout << "No items in the list or to delete.\n";
    }

    print_menu(name);
    
}

void print_list() {

    cout << "\n\n\n\n\n\n";
    cout << "*** Printing List ***";

    for(int list_index=0; list_index < list.size(); list_index++){
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - Menu \n";
    char choice;
    cin >> choice;

    if( choice == "M" || choice == "m"){
        print_menu(name);
    }
    else {
        cout << "Invalid Choice. Quitting...\n";
    }
}