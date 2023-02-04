#include "Matrix.hpp"
#include <iostream>
Matrix::Matrix(string n, int parameter_row, int parameter_col):name(n) 
{
    square = false;
    if(parameter_col == -1)
    {
        parameter_col = parameter_row;
        square = true;
    }
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
bool Matrix::is_diagonal()const
{
    if(!square)
        return false;

    for(size_t i = 0; i < row; i++)
        for(size_t j = 0; j < col; j++)
            if(i != j && matris[i][j] != 0)
                return false;

    return true;
}
bool Matrix::is_lower_triangular()const
{
    if(!square)
        return false;
    
    for(size_t i = 0; i < row - 1; i++)
        for(size_t j = i + 1; j < col; j++)
            if(matris[i][j] != 0)
                return false;
    
    return true;
}
bool Matrix::is_upper_triangular()const
{
    if(!square)
        return false;
    
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i ; j++)
            if(matris[i][j] != 0)
                return false;
    
    return true;

}
bool Matrix::is_identity()const
{
    if(!(this->is_upper_triangular() && this->is_lower_triangular()))
        return false;
        
    for(size_t i = 0; i<row; i++)
        if(matris[i][i] != 1)
            return false;

    return true;
}
bool Matrix::is_normal_symmetric()const
{
    if(!square)
        return false;
    
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i; j++)
            if(matris[i][j] != matris[j][i])
                return false;

    return true;
}
bool Matrix::is_skew_symmetric()const
{
    if(!square)
        return false;
    
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i; j++)
            if(matris[i][j] + matris[j][i] != 0)
                return false;

    return true;

}
void Matrix::change(int _row, int _col, int amount)
{
    if(_row < row && _col < col)
        matris[_row][_col] = amount;
    else
        cout << "change: input coordinates are out of range\n";
}
Matrix* Matrix::inverse(string n)
{
    if(!square)
        return nullptr;
    if(n == "")
    {
        for(size_t i = 1; i< row; i++)
            for(size_t j = 0 ; j < i; j++)
            {
                matris[i][j] += matris[j][i];
                matris[j][i] = matris[i][j] - matris[j][i];
                matris[i][j] -= matris[j][i];
            }
        return nullptr;
    }
}
void Matrix::destructor()
{
    for(size_t i = 0; i < row; i++)
        delete [] matris[i];
    delete [] matris;
}