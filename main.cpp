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
        if(command.size() >= 10 && command.substr(0, 10) == "add matrix")
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
        else if(command.size() >= 4 && command.substr(0, 4) == "show")
        {
            if(command.size() >= 5)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(5));
                if(mat != nullptr)
                    mat->show();
                else
                    cout << "show: cannot find '" << command.substr(5) << "': No such Matrix" << endl; 
            }
            else
                cout << "show: missing operand\n";

        }
        else if(command.size() >= 11 && command.substr(0, 11) == "is_diagonal")
        {
            if(command.size() >= 12)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(12));
                if(mat != nullptr)
                    cout << command.substr(12) << "IS " <<(mat->is_diagonal()? "" : "NOT " )<< "diagonal" << endl;
                else
                    cout << "is_diagonal: cannot find '" << command.substr(12) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_diagonal: missing operand\n";
        }
        else if(command.size() >= 19 && command.substr(0, 19) == "is_lower_triangular")
        {
            if(command.size() >= 20)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(20));
                if(mat != nullptr)
                    cout << command.substr(20) << "IS " <<(mat->is_lower_triangular()? "" : "NOT " )<< "lower triangular" << endl;
                else
                    cout << "is_diagonal: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_lower_triangular: missing operand\n";
        }
        else if(command.size() >= 19 && command.substr(0, 19) == "is_upper_triangular")
        {
            if(command.size() >= 20)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(20));
                if(mat != nullptr)
                    cout << command.substr(20) << "IS " <<(mat->is_upper_triangular()? "" : "NOT " )<< "upper triangular" << endl;
                else
                    cout << "is_diagonal: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_lower_triangular: missing operand\n";
        }
        else if(command.size() >= 13 && command.substr(0, 13) == "is_triangular")
        {
            if(command.size() >= 14)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(14));
                if(mat != nullptr)
                {
                    bool U = mat->is_upper_triangular();
                    bool L = mat->is_lower_triangular();
                    cout << command.substr(14) << "IS ";
                    if(U && L)
                        cout << "upper and lower triangular";
                    else if(!(U || L))
                        cout << "nothing";
                    else
                    {
                        cout << (U? "just upper": "just lower") << " triangular";
                    }
                    cout << endl;
                }
                else
                    cout << "is_diagonal: cannot find '" << command.substr(14) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_lower_triangular: missing operand\n";
        }
        else if(command.size() >= 11 && command.substr(0, 11) == "is_identity")
        {
            if(command.size() >= 12)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(12));
                if(mat != nullptr)
                    cout << command.substr(12) << "IS " <<(mat->is_identity()? "" : "NOT " )<< "identity" << endl;
                else
                    cout << "is_identity: cannot find '" << command.substr(12) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_identity: missing operand\n";
        }
        else if(command.size() >= 17 && command.substr(0, 17) == "is_identity")
        {
            if(command.size() >= 18)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(18));
                if(mat != nullptr)
                    cout << command.substr(18) << "IS " <<(mat->is_identity()? "" : "NOT " )<< "identity" << endl;
                else
                    cout << "is_identity: cannot find '" << command.substr(18) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_identity: missing operand\n";
        }
        else if(command.size() >= 19 && command.substr(0, 19) == "is_normal_symmetric")
        {
            if(command.size() >= 20)
            {
                Matrix* mat = find_Matrix(user_matris ,command.substr(11));
                if(mat != nullptr)
                    cout << command.substr(20) << "IS " <<(mat->is_identity()? "" : "NOT " )<< "identity" << endl;
                else
                    cout << "is_identity: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_identity: missing operand\n";
        }
        else
        {
            int pos = command.find(' ');
            cout << command.substr(0, pos) << ": command not found\n";
        }
    }while(1);

    for(auto& item: user_matris)
    {
        item->destructor();
        delete item;
    }
    return 0;
}