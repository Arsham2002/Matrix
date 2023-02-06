
#ifndef __OPERATOR_OVERLOADED_HPP
#define __OPERATOR_OVERLOADED_HPP
#include "Matrix.hpp"

void print_menu()//Prints menu and commands
{
    cout << "Exit: exit \nAdd: add matrix 'name' 'row' 'col' You can even enter";
    cout << " directly like this--> \n[a,b,c,...] (if matrix is square just ent";
    cout << "er row) \nDiagonal: is_diagonal 'name' \nUpper/Lower triangular: i";
    cout << "s_upper/lower_triangular 'name' \nTriangular: is_triangular 'name'";
    cout << " \nIdentity: is_identity 'name' \nNormal/Skew symmetric: is_normal";
    cout << "/skew_symmetric 'name' \nSymmetric: is_symmetric 'name' \nInverse:";
    cout << " inverse 'name' or inverse 'name' 'name of matrix 2' \nShow: show ";
    cout << "'name' \nDelete: delete 'name' \nChange an element: change 'name' ";
    cout << "'row' 'column' 'new element \n";
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
