#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"
#include "functions.hpp"
using namespace std;
int main()
{
    vector<Matrix*> user_matris;
    string command;
    cout << "Exit: exit\n";
    do
    {
        getline(cin, command, '\n');
        if(command == "exit")
            break;
        if(command.substr(0, 10) == "add matrix")
        {
            int pos_name = command.find(' ', 11);//find space after matrix name
            string index = command.substr(pos_name + 1);
            switch(index.size())
            {
                case 1:
                    user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index)));
                    break;
                case 3:
                    user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index), stoi(index.substr(2,3))));
                    break;
                default:
                    cout << "add matrix: missing operand\n";
            }
        }
        else if(command.substr(0, 4) == "show")
        {
            Matrix* mat = find_Matrix(user_matris ,command.substr(5));
            if(mat != nullptr)
                mat->show();
            else
                cout << "show: cannot find '" << command.substr(5) << "': No such Matrix" << endl; 
        }
        else
            cout << command << ": command not found\n";
    }while(1);
    for(auto& item: user_matris)
    {
        item->destructor();
        delete item;
    }
    return 0;
}