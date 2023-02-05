#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include "Matrix.hpp"
#include "functions.hpp"
using namespace std;
int main()// line 253 and fix constructor 
{
    vector<Matrix*> user_matris;
    string command;
    cout << "Exit: exit \nAdd: add matrix 'name' 'row' 'col' You can even enter di";
    cout << "rectly like this--> \n [a,b,c,...] (if matrix is square just enter ro";
    cout << "w) \nDiagonal: is_diagonal 'name' \nUpper/Lower trangular: is_upper/l";
    cout << "ower_trangular 'name' \nTrangular: is_trangular 'name' \nIdentity: is";
    cout << "_identity 'name' \nNormal/Skew symmetric: is_normal/skew_symmetric 'n";
    cout << "ame' \nSymmetric: is_symmetric 'name' \n Inverse: inverse 'name' or i";
    cout << "nverse 'name' 'name of matrix 2' \nShow: show 'name' \nDelete: delete";
    cout << " 'name' \nChange an element: change 'name' 'row' 'column' 'new elemen";
    cout << "t \n";
    do
    {
        getline(cin, command, '\n');
        if(command == "exit")
            break;
        if(command.size() >= 10 && command.substr(0, 10) == "add matrix")
        {
            if(command.size() >= 12)
            {
                int pos_name = command.find(' ', 11);//find space after matrix name
                string index = command.substr(pos_name + 1);
                if(index.size() == 1)
                {
                        user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index)));
                        user_matris.back()->fill_from_user();
                }
                else if(index.size() == 3)
                {
                        user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), stoi(index), stoi(index.substr(2,3))));
                        user_matris.back()->fill_from_user();                    
                }
                else if(index.size() >= 2 && index.size() != command.size())
                {
                    int _row = stoi(index);
                    int _col = _row;
                    size_t i = 3;
                    if(index[4] == '[')
                    {
                        _col = stoi(index.substr(2, 3));
                        i = 5;
                    }
                    if(_row * _col * 2 == (index.substr(i)).size())
                    {
                        user_matris.push_back(new Matrix(command.substr(11, pos_name - 11), _row, _col));
                        for(size_t j = 1; j <= _row * _col; i+= 2, j++)
                            user_matris.back()->fill_auto(stoi(index.substr(i , i+1)));
                    }
                    else
                        cout << "add matrix: missing operand\n";   

                }
                else
                    cout << "add matrix: missing operand\n";
            }       
            else
                cout << "add matrix: missing operand\n";
        }
        else if(command.size() >= 4 && command.substr(0, 4) == "show")
        {
            if(command.size() >= 5)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(5), k);
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
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(12), k);
                if(mat != nullptr)
                    cout << command.substr(12) << " IS " <<(mat->is_diagonal()? "" : "NOT " )<< "diagonal" << endl;
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
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(20), k);
                if(mat != nullptr)
                    cout << command.substr(20) << " IS " <<(mat->is_lower_triangular()? "" : "NOT " )<< "lower triangular" << endl;
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
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(20), k);
                if(mat != nullptr)
                    cout << command.substr(20) << " IS " <<(mat->is_upper_triangular()? "" : "NOT " )<< "upper triangular" << endl;
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
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(14), k);
                if(mat != nullptr)
                {
                    bool U = mat->is_upper_triangular();
                    bool L = mat->is_lower_triangular();
                    cout << command.substr(14) << " IS ";
                    if(U && L)
                        cout << "upper and lower triangular";
                    else if(!(U || L))
                        cout << "NOT triangular";
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
                cout << "is_triangular: missing operand\n";
        }
        else if(command.size() >= 11 && command.substr(0, 11) == "is_identity")
        {
            if(command.size() >= 12)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(12), k);
                if(mat != nullptr)
                    cout << command.substr(12) << " IS " <<(mat->is_identity()? "" : "NOT " )<< "identity" << endl;
                else
                    cout << "is_identity: cannot find '" << command.substr(12) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_identity: missing operand\n";
        }
        else if(command.size() >= 17 && command.substr(0, 17) == "is_skew_symmetric")
        {
            if(command.size() >= 18)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(18), k);
                if(mat != nullptr)
                    cout << command.substr(18) << " IS " <<(mat->is_skew_symmetric()? "" : "NOT " )<< "skew symmetric" << endl;
                else
                    cout << "is_skew_symmetric: cannot find '" << command.substr(18) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_skew_symmetric: missing operand\n";
        }
        else if(command.size() >= 19 && command.substr(0, 19) == "is_normal_symmetric")
        {
            if(command.size() >= 20)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(11), k);
                if(mat != nullptr)
                    cout << command.substr(20) << " IS " <<(mat->is_normal_symmetric()? "" : "NOT " )<< "normal symmetric" << endl;
                else
                    cout << "is_normal_symetric: cannot find '" << command.substr(20) << "': No such Matrix" << endl; 
            }
            else
                cout << "is_normal_symmetric: missing operand\n";
        }
        else if(command.size() >= 12 && command.substr(0, 12) == "is_symmetric")
        {
            if(command.size() >= 13)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(13), k);
                if(mat != nullptr)
                {
                    bool N  = mat->is_normal_symmetric();
                    bool S = mat->is_skew_symmetric();
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
                cout << "is_symetric: missing operand\n";
        }
        else if(command.size() >= 6 && command.substr(0,6) == "delete")
        {
            if(command.size() >= 7)
            {
                int k;
                Matrix* mat = find_Matrix(user_matris ,command.substr(7), k);
                if(mat != nullptr)
                {
                    mat->destructor();
                    user_matris.erase(user_matris.begin() + k);
                }
                else
                    cout << "delete: cannot find '" << command.substr(7) << "': No such Matrix" << endl; 

            }
            else
                cout << "delete: missing operand\n";
        }
        else if(command.size() >= 6 && command.substr(0, 6) == "change")
        {
            if(command.size() >= 7)
            {
                int k;
                int pos_name = command.find(' ', 7);
                if(pos_name != -1)
                {
                    Matrix* mat = find_Matrix(user_matris ,command.substr(7, pos_name-7), k);
                    if(mat != nullptr)
                    {
                        string index = command.substr(pos_name + 1);
                        if(index.size() >= 5)
                        {
                            mat->change(stoi(index), stoi(index.substr(2,3)), stoi(index.substr(4)));
                        }
                        else
                            cout << "add matrix: missing operand\n";
                        
                    }
                    else
                        cout << "change: cannot find '" << command.substr(7, pos_name-7) << "': No such Matrix" << endl; 
                }
                else
                    cout << "change: missing operand\n";

            }
            else
                cout << "change: missing operand\n";

        }
        else if(command.size() >= 7 && command.substr(0,7) == "inverse")
        {
            if(command.size() >= 8)
            {
                int k;
                bool two = true;
                int pos_name = command.find(' ', 8);
                if(pos_name == -1)
                {
                    pos_name = command.size();
                    two = false;
                }
                Matrix* mat = find_Matrix(user_matris ,command.substr(8, pos_name-8), k);
                if(mat != nullptr)
                {
                    if(two)
                    {
                        Matrix* mat2 = (mat->inverse(command.substr(pos_name + 1)));
                        user_matris.push_back(mat2);    
                    }
                    else
                        mat->inverse(command.substr(8, pos_name-8));
                }
                else
                    cout << "inverse: cannot find '" << command.substr(8) << "': No such Matrix" << endl; 

            }
            else
                cout << "inverse: missing operand\n";

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