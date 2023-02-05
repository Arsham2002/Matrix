#include "app.hpp"
#include <iostream>
using namespace std;
bool App::run(string _command)
{
    command = _command;
    miss_operand = false;
    int pos = command.find(' ');//The index of the first space

    if(command == "exit")
        return false;

    if(command.size() >= 19 && command.substr(0, 19) == "is_normal_symmetric")
        is_normal_symmetric_command();

    else if(command.size() >= 19 && command.substr(0, 19) == "is_lower_triangular")
        is_lower_triangular_command();

    else if(command.size() >= 19 && command.substr(0, 19) == "is_upper_triangular")
        is_upper_triangular_command(); 

    else if(command.size() >= 17 && command.substr(0, 17) == "is_skew_symmetric")
        is_skew_symmetric_command();

    else if(command.size() >= 13 && command.substr(0, 13) == "is_triangular")
        is_lower_triangular_command();

    else if(command.size() >= 12 && command.substr(0, 12) == "is_symmetric")
        is_symmetric_command();

    else if(command.size() >= 11 && command.substr(0, 11) == "is_diagonal")
        is_diagonal_command();

    else if(command.size() >= 11 && command.substr(0, 11) == "is_identity")
        is_identity_command();

    else if(command.size() >= 10 && command.substr(0, 10) == "add matrix")
        add_matrix_command(); 
        
    else if(command.size() >= 7 && command.substr(0,7) == "inverse")
        inverse_command();

    else if(command.size() >= 6 && command.substr(0,6) == "delete")
        delete_command();

    else if(command.size() >= 6 && command.substr(0, 6) == "change")
        change_command();
 
    else if(command.size() >= 4 && command.substr(0, 4) == "show")
        show_command();

    else
        cout << command.substr(0, pos) << ": command not found\n";

    if(miss_operand)
        cout << command.substr(0, pos) << ": missing operand\n";
        
    return true;

}

void App::add_matrix_command()
{
    if(command.size() >= 12)//This command must have at least 12 characters
    {
        int pos_name = command.find(' ', 11);//The index of the first space after the text of the command
        string index = command.substr(pos_name + 1);//row and column input
        if(index.size() == 1)//square matrix(user just enter one number)
        {
                user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index)));
                user_matris.back()->fill_from_user();
        }
        else if(index.size() == 3)
        //Rectangle matrix(user enter two number for row and column)
        {
                user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index), stoi(index.substr(2,3))));
                user_matris.back()->fill_from_user();                    
        }
        else if(index.size() >= 2 && index.size() != command.size())
        //The user wants to create a matrix with default values
        {
            int _row = stoi(index);
            int _col = _row;
            size_t i = 3;
            if(index[4] == '[')
            //If the matrix is ​​rectangular, the first bracket falls in this house
            {
                _col = stoi(index.substr(2, 3));
                i = 5;
            }
            if(_row * _col * 2 == (index.substr(i)).size())
            //All the necessary values ​​have been entered
            {
                user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), _row, _col));
                for(size_t j = 1; j <= _row * _col; i+= 2, j++)
                    user_matris.back()->fill_auto(stoi(index.substr(i , i+1)));
            }
            else
                miss_operand = true;  

        }
        else
            miss_operand = true;  
    }       
    else
        miss_operand = true; 
}

void App::show_command()
{
    if(command.size() >= 5)
    {
        int k = find_Matrix(user_matris ,command.substr(5));
        if(k != -1)
            user_matris[k]->show();
        else
            cout << "show: cannot find '" << command.substr(5) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true;
}

void App::is_diagonal_command()
{
    if(command.size() >= 12)
    {
        int k = find_Matrix(user_matris ,command.substr(12));
        if(k != -1)
            cout << command.substr(12) << " IS " <<(user_matris[k]->is_diagonal()? "" : "NOT " )<< "diagonal" << endl;
        else
            cout << "is_diagonal: cannot find '" << command.substr(12) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true;  
}

void App::is_lower_triangular_command()
{
        if(command.size() >= 20)
        {
            int k = find_Matrix(user_matris ,command.substr(20));
            if(k != -1)
                cout << command.substr(20) << " IS " <<(user_matris[k]->is_lower_triangular()? "" : "NOT " )<< "lower triangular" << endl;
            else
                cout << "is_diagonal: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
        }
        else
            miss_operand = true;  
}

void App::is_upper_triangular_command()
{
    if(command.size() >= 20)
    {
        int k = find_Matrix(user_matris ,command.substr(20));
        if(k != -1)
            cout << command.substr(20) << " IS " <<(user_matris[k]->is_upper_triangular()? "" : "NOT " )<< "upper triangular" << endl;
        else
            cout << "is_diagonal: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true; 
}

void App::is_triangular()
{
    if(command.size() >= 14)
    {
        int k = find_Matrix(user_matris ,command.substr(14));
        if(k != -1)
        {
            bool U = user_matris[k]->is_upper_triangular();
            bool L = user_matris[k]->is_lower_triangular();
            cout << command.substr(14) << " IS ";
            if(U && L)
                cout << "upper and lower triangular";
            else if(!(U || L))
                cout << "NOT triangular";
            else
                cout << (U? "just upper": "just lower") << " triangular";

            cout << endl;
        }
        else
            cout << "is_diagonal: cannot find '" << command.substr(14) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true;  
}

void App::is_identity_command()
{
    if(command.size() >= 12)
    {
        int k = find_Matrix(user_matris ,command.substr(12));
        if(k != -1)
            cout << command.substr(12) << " IS " <<(user_matris[k]->is_identity()? "" : "NOT " )<< "identity" << endl;
        else
            cout << "is_identity: cannot find '" << command.substr(12) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true; 
}

void App::is_skew_symmetric_command()
{
    if(command.size() >= 18)
        {
            int k = find_Matrix(user_matris ,command.substr(18));
            if(k != -1)
                cout << command.substr(18) << " IS " <<(user_matris[k]->is_skew_symmetric()? "" : "NOT " )<< "skew symmetric" << endl;
            else
                cout << "is_skew_symmetric: cannot find '" << command.substr(18) << "': No such Matrix" << endl; 
        }
        else
            miss_operand = true; 
}

void App::is_normal_symmetric_command()
{
    if(command.size() >= 20)
    {
            int k = find_Matrix(user_matris ,command.substr(20));
            if(k != -1)
            cout << command.substr(20) << " IS " <<(user_matris[k]->is_normal_symmetric()? "" : "NOT " )<< "normal symmetric" << endl;
        else
            cout << "is_normal_symetric: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true;  
}

void App::is_symmetric_command()
{
    if(command.size() >= 13)
    {
        int k = find_Matrix(user_matris ,command.substr(13));
        if(k != -1)
        {
            bool N  = user_matris[k]->is_normal_symmetric();
            bool S = user_matris[k]->is_skew_symmetric();
            cout << command.substr(13) << " IS ";
            if(!(S || N))
                cout << "NOT symmetric";
            else
            {
                cout << (N? "just Normal": "just Skew") << " symmetric";
            }
            cout << endl;
        }
        else
            cout << "is_symmetric: cannot find '" << command.substr(13) << "': No such Matrix" << endl; 
    }
    else
        miss_operand = true;  
}

void App::delete_command()
{
    if(command.size() >= 7)
    {
        int k = find_Matrix(user_matris ,command.substr(7));
        if(k != -1)
        {
            user_matris[k]->destructor();
            user_matris.erase(user_matris.begin() + k);
        }
        else
            cout << "delete: cannot find '" << command.substr(7) << "': No such Matrix" << endl; 

    }
    else
        miss_operand = true;  
}

void App::change_command()
{
    if(command.size() >= 7)
    {
        int pos_name = command.find(' ', 7);
        if(pos_name != -1)
        {
            int k = find_Matrix(user_matris ,command.substr(7));
            if(k != -1)
            {
                string index = command.substr(pos_name + 1);
                if(index.size() >= 5)
                {
                    user_matris[k]->change(stoi(index), stoi(index.substr(2,3)), stoi(index.substr(4)));
                }
                else
                    miss_operand = true; 
            }
            else
                cout << "change: cannot find '" << command.substr(7, pos_name-7) << "': No such Matrix" << endl; 
        }
        else
        miss_operand = true;  
    }
    else
        miss_operand = true;  
}

void App::inverse_command()
{

    if(command.size() >= 8)
    {
        bool two = true;//Has the user requested to create a second matrix?
        int pos_name = command.find(' ', 9);
        if(pos_name == -1)
        {
            pos_name = command.size();
            two = false;
        }
        int k = find_Matrix(user_matris ,command.substr(8, pos_name - 8));
        if(k != -1)
        {
            if(two)
            {
                Matrix* mat2 = (user_matris[k]->inverse(command.substr(pos_name + 1)));
                user_matris.push_back(mat2);    
            }
            else
                user_matris[k]->inverse(command.substr(8, pos_name-8));
        }
        else
            cout << "inverse: cannot find '" << command.substr(8) << "': No such Matrix" << endl; 

    }
    else
        cout << "inverse: missing operand\n";
}

App::~App()
{
    for(auto& item: user_matris)
    {
        item->destructor();
        delete item;
    }
}