#include "Matrix.hpp"
#include <iostream>
Matrix::Matrix(string n, int parameter_row, int parameter_col):name(n) 
{
    if(parameter_col == -1)
        parameter_col = parameter_row;
    row  = parameter_row;
    col = parameter_col;
    matris = new int* [row];
    for(size_t i = 0 ; i<row ; i++)
    {
        matris[i] = new int[col];
        for(size_t j = 0 ; j <col ;j++)
        {
            cout << "Enter element in (" << i << "," << j <<"): ";
            cin >> matris[i][j];
        }
    }
    getline(cin, n,'\n');
}
void Matrix::show()const
{
    for(size_t i = 0; i < row; i++)
    {
        for(size_t j = 0; j < col; j++)
            cout << matris[i][j] << " ";
        cout << endl;
    }
}
void Matrix::destructor()
{
    cout << "is: " << name  << " row and col: " << row << " " << col << endl;
    for(size_t i = 0; i < row; i++)
        delete [] matris[i];
    delete [] matris;
}