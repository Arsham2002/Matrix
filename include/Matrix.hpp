
#ifndef __MATRIX_HPP
#define __MATRIX_HPP
#include <string>
#include <vector>
using namespace std;

class Matrix
{
    friend Matrix* find_Matrix(vector<Matrix*> ,string);
    private:
    string name;
    int** matris; 
    int row;
    int col;
    bool square;

    public:
    Matrix(string, int a, int = -1);
    void show()const;
    void destructor();
    bool is_diagonal()const;
    bool is_lower_triangular()const;
    bool is_upper_triangular()const;
    bool is_identity()const;
};

#endif // __MATRIX_HPP
