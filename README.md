# Master C++ programming on Linux



Resources: https://www.youtube.com/watch?v=TZANnCMJxUE&list=PLKMOdY6Bhga5ws13FNCbD0103pXEP-VFV



## Part 1- Environment Setup

- Install VS Code
- Install Packages in VS Code:
  - **C/C++ IntelliSense** from Microsoft, with 70M downloads.
  - **Code Runner** from Jun Han with 29M downloads

* Optionally install gcc compiler only if Ubuntu/Debian has not brought it up

  ```
  sudo apt install build-essential gdb
  gcc --version
  
  ## For ArchLinux, the command is:
  ## sudo pacman -S base-devel
  ```



## Part 2- Hello World app

 - ```c++
   #include <iostream>
   
   int main(){
   
       std::cout << "Hello World!" << std::endl;
       return 0;
   
   }
   ```



### - Install C/C++ makefile

* Features of `makefile`
  * automation of Build Process
  * manage dependencies
  * compile/build multiple sources
  * keeps track of compilations
* install **C/C++ Makefile** from Adriano Markovic



### - Using make

* configure the Makefile

* move main.cpp to `src` folder

* from terminal 

  ```
  make
  ```

* ### Run the app

  ```
  SimpleList
  ```

  

* ### Why learning C++?

  * Efficient + performance: full access to RAM
  * portability -> any system (anywhere)
  * stable -> 40 years (System V)
  * standardization



## Part 3 - Making our C++ Program

* args

  * arg[0] <- program name

  * arg[1] <- 1st arg

  * ...

  * arg[n] <- nth arg

* User input
* Make better choice program



## Part 4 - Vectors 

The cpp is as below so far:

```c++
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
```



## Part 5- Adding Menu Choices

Here you are:

```c++
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
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press enter: \n";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n\n\n\n";
    cin.clear();

    print_menu(name);
}

void delete_item() {
    
    cout << "*** Delete Item ***\n";
    cout << "Select an item index to delete\n";

    if(list.size()) {
        for(int i=0; i < list.size(); i++) {
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
    cout << "*** Printing List ***\n";

    for(int list_index=0; list_index < list.size(); list_index++) {
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - Menu \n";
    char choice;
    cin >> choice;

    if( choice == 'M' || choice == 'm'){
        print_menu(name);
    }
    else {
        cout << "Invalid Choice. Quitting...\n";
    }
}
```



## Part 6 - Classes and Objects



Fix the issue of warning by type cast, fir instance: at line 96, add `int()` to `list.size()` as:

```
for(int list_index=0; list_index < int(list.size()); list_index++){
	cout << " * " << list[list_index] << "\n";
}
```

But type casting may lose the precision, then a better way is to `unsign` the list_index as below:

```
for(unsigned int list_index=0; list_index < list.size(); list_index++){
	cout << " * " << list[list_index] << "\n";
}
```



### Classes and Objects

Add a header file in `src/include/` folder: `src/include/list.h`

`src/include/list.h` file:

```
#include <iostream>
#include <vector>
using namespace std;

class List {
    private:

    protected:

    public:

        List() {
            //constructor
        }
        ~List() {
            //destructor
        }

        vector<string> list;
        string name;

        void print_menu();
        void print_list();
        void add_item();
        void delete_item();
};
```



`src/list.cpp` file:

```
#include "include/list.h"

void List::print_menu() {
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

void List::add_item(){

    cout << "\n\n\n\n\n";
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press enter: \n";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n\n\n\n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    
    cout << "*** Delete Item ***\n";
    cout << "Select an item index to delete\n";

    if(list.size()) {
        for(unsigned int i=0; i < list.size(); i++) {
            cout << i << ": " << list[i] << "\n";
        }
    }
    else {
        cout << "No items in the list or to delete.\n";
    }

    print_menu();
    
}

void List::print_list() {

    cout << "\n\n\n\n\n\n";
    cout << "*** Printing List ***\n";

    for(unsigned int list_index=0; list_index < list.size(); list_index++) {
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - Menu \n";
    char choice;
    cin >> choice;

    if( choice == 'M' || choice == 'm'){
        print_menu();
    }
    else {
        cout << "Invalid Choice. Quitting...\n";
    }
}
```



`src/main.cpp` file:

```
#include "include/list.h"

int main(int arg_count, char *args[]){

    if(arg_count > 1) {
        List simpleList;
        simpleList.name = string(args[1]);
        simpleList.print_menu();
    }
    else {
        cout << "Username not supplied.. exiting the program" << endl;
    }

    return 0;

}
```



## Part 7- Source Control with Git



1:41:20
