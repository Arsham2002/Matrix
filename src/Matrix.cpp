#include "Matrix.hpp"
#include <iostream>
Matrix::Matrix(string n, int parameter_row, int parameter_col):name(n) 
/*Construct the matrix object whit name 'n' and
  row 'parameter_row' and column 'parameter_column'*/
{
    square = false;

    if(parameter_col == -1 || parameter_col == parameter_row)
    /*if col and row parameter are the same or column is not 
      passed as the second  parameter, so row and column are
      the same(The default value of the column is -1)*/
    {
        parameter_col = parameter_row;
        square = true;
    }

    row  = parameter_row;
    col = parameter_col;

    /*The required memory of a two-dimensional
      -matrix is ​​taken in these few lines*/
    matris = new int* [row];
    for(size_t i = 0 ; i<row ; i++)
    {
        matris[i] = new int[col];
    }
}
void Matrix::fill_from_user()
{
    for(size_t i = 0 ; i < row; i++)
        for(size_t j = 0 ; j <col ;j++)
        {
            cout << "Enter element in (" << i << "," << j <<"): ";
            cin >> matris[i][j];
        }
    string n;
    getline(cin, n,'\n');
}
void Matrix::fill_auto(int e)
/*This function is for filling the matrix once from the beginning to the end
  with specified values ​​(of course, to fill the entire matrix, this function must be called as many members of the matrix with the desired value)*/
{
    static int k = 0;//How many times has this function been called so far?
    matris[k/col][k%col] = e;
    /*The desired row depends on how many rows have been filled so far,
      and the column depends on how many columns the remainder k is*/
    k++;
    if(k == row * col)//Reset function for next time
        k = 0;
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
    if(!square)//Only square matrix can be diagonal
        return false;

    for(size_t i = 0; i < row; i++)
        for(size_t j = 0; j < col; j++)
            if(i != j && matris[i][j] != 0)
                return false;

    return true;
}
bool Matrix::is_lower_triangular()const
{
    if(!square)//Only square matrix can be lower triangular
        return false;
    //Only checking members upper the main diameter(which must be 0)
    for(size_t i = 0; i < row - 1; i++)
        for(size_t j = i + 1; j < col; j++)
            if(matris[i][j] != 0)
                return false;
    
    return true;
}
bool Matrix::is_upper_triangular()const
{
    if(!square)//Only square matrix can be triangular
        return false;
    //Only checking members lower the main diameter(which must be 0)
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i ; j++)
            if(matris[i][j] != 0)
                return false;
    
    return true;

}
bool Matrix::is_identity()const
{
    //Only a matrix can be an identity that is both upper and lower triangular
    if(!(this->is_upper_triangular() && this->is_lower_triangular()))
        return false;
    
    for(size_t i = 0; i<row; i++)
        if(matris[i][i] != 1)
            return false;

    return true;
}
bool Matrix::is_normal_symmetric()const
{
    if(!square)//Only square matrix can be triangular
        return false;
    /*Checking members below the main diameter with their
      corresponding members above the main diameter*/
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i; j++)
            if(matris[i][j] != matris[j][i])
                return false;

    return true;
}
bool Matrix::is_skew_symmetric()const
{
    if(!square)//Only square matrix can be triangular
        return false;

    /*Checking members below the main diameter with their
      corresponding members above the main diameter*/
    for(size_t i = 1; i < row; i++)
        for(size_t j = 0; j < i; j++)
            if(matris[i][j] + matris[j][i] != 0)
                return false;

    return true;

}
void Matrix::change(int _row, int _col, int amount)
//Change the value in row '_row' and column '_col' to 'amount'
{
    if(_row < row && _col < col)
        matris[_row][_col] = amount;
    else
        cout << "change: input coordinates are out of range\n";
}
Matrix* Matrix::inverse(string n)
/*Reverses the matrix named 'n' and returns the address of
  the new matrix instead of the nullptr if the user requests 
  to create a new matrix.*/
{
    if(!square)//Only square matrix can be inverted
        return nullptr;
    if(n == name)//No request to create a second matrix by the user
    {
        /*In the inversion of the matrix, the main diameter does not change,
          and the members below the main diameter are moved with their corresponding members above the diameter.*/
        for(size_t i = 1; i< row; i++)
            for(size_t j = 0 ; j < i; j++)
            {
                matris[i][j] += matris[j][i];
                matris[j][i] = matris[i][j] - matris[j][i];
                matris[i][j] -= matris[j][i];
            }
        return nullptr;
    }
    else
    {
        Matrix* m = new Matrix(n, row, col);
        /*In inversion, the location of each member is moved with
          its corresponding location relative to the main diameter*/
        for(size_t i = 0 ; i < row; i++)
            for(size_t j = 0 ; j <= i; j++)
            {
                m->matris[i][j] = matris[j][i];
                m->matris[j][i] = matris[i][j];
            }
        return m;
    }
}
void Matrix::destructor()
{
    for(size_t i = 0; i < row; i++)
        delete [] matris[i];
    delete [] matris;
}