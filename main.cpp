#include <iostream>
#include "app.hpp"
#include "functions.hpp"
int main()
{
    App a;//I used this class to shorten the main function
    print_menu();//In this line, the menu is printed for the user
    string command;

    do
    {
        getline(cin, command, '\n');
    }while(a.run(command));
    /*The run function for the app class 
      returns false if the user enters exit*/

    return 0;
}