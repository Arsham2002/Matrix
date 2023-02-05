
#ifndef __MATRIX_HPP
#define __MATRIX_HPP
#include <string>
#include <vector>
using namespace std;

class Matrix
{
    friend int find_Matrix(const vector<Matrix*>& ,string);
    //Due to the need to access the names of the matrices in the vector
    private:
        string name;//The name of the matrix
        int** matris; //The values ​​in the two-dimensional matrix
        int row;//Number of rows
        int col;//Number of columns
        bool square;//Is it a square matrix or not?

    public:
        Matrix(string, int, int = -1);//Description in the implementation section

        void fill_from_user();//Matrix members are taken directly from the user
        void fill_auto(int);//Description in the implementation section
        void show()const;//Print members of matrix
        void change(int, int, int);//Description in the implementation section

        bool is_diagonal()const;//Is it the diagonal matrix?
        bool is_lower_triangular()const;//Is it the lower triangular matrix?
        bool is_upper_triangular()const;//Is it the upper triangular matrix?
        bool is_identity()const;//Is it the identity matrix?
        bool is_normal_symmetric()const;//Is it the normal symmetric matrix?
        bool is_skew_symmetric()const;//Is it the skew symmetric matrix?

        Matrix* inverse(string);//Description in the implementation section

        void destructor();//Frees the spaces occupied by the object matrix(int** matris)

};

#endif // __MATRIX_HPP
