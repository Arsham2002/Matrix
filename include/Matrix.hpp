
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
    public:
    Matrix(string, int a, int = -1);
    void show()const;
    void destructor();

};

#endif // __MATRIX_HPP
