# Master C++ programming on Linux



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

 - ```
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



Part 4 - Vectors 

--> 01:00:00