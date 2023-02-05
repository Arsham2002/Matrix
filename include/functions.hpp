
#ifndef __OPERATOR_OVERLOADED_HPP
#define __OPERATOR_OVERLOADED_HPP
#include "Matrix.hpp"

void print_menu()//Prints menu and commands
{
    cout << "Exit: exit \nAdd: add matrix 'name' 'row' 'col' You can even enter di";
    cout << "rectly like this--> \n[a,b,c,...] (if matrix is square just enter ro";
    cout << "w) \nDiagonal: is_diagonal 'name' \nUpper/Lower trangular: is_upper/l";
    cout << "ower_trangular 'name' \nTrangular: is_trangular 'name' \nIdentity: is";
    cout << "_identity 'name' \nNormal/Skew symmetric: is_normal/skew_symmetric 'n";
    cout << "ame' \nSymmetric: is_symmetric 'name' \nInverse: inverse 'name' or i";
    cout << "nverse 'name' 'name of matrix 2' \nShow: show 'name' \nDelete: delete";
    cout << " 'name' \nChange an element: change 'name' 'row' 'column' 'new elemen";
    cout << "t \n";
}

int find_Matrix(const vector<Matrix*>& matris, string n)
/*Looks for a matrix named 'n' in the matrix vector and returns the index
  (if there is no returns -1)*/
{
    int index = 0;
    for(auto item: matris)
    {
        if(item->name == n)
            return index;
        index++;
    }
    return -1;
}


#endif // __OPERATOR_OVERLOADED_HPP
