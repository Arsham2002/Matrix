
#ifndef __MATRIX_HPP
#define __MATRIX_HPP
#include <string>
#include <vector>
using namespace std;

class Matrix
{
    friend Matrix* find_Matrix(vector<Matrix*> ,string, int&);
    private:
    string name;
    int** matris; 
    int row;
    int col;
    bool square;

    public:
    Matrix(string, int a, int = -1);
    void show()const;
    void change(int, int, int);
    void destructor();
    bool is_diagonal()const;
    bool is_lower_triangular()const;
    bool is_upper_triangular()const;
    bool is_identity()const;
    bool is_normal_symmetric()const;
    bool is_skew_symmetric()const;
    Matrix* inverse(string = "");

};

#endif // __MATRIX_HPP
