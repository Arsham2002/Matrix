
#ifndef __OPERATOR_OVERLOADED_HPP
#define __OPERATOR_OVERLOADED_HPP
#include "Matrix.hpp"
Matrix* find_Matrix(vector<Matrix*> matris, string n)
{
    for(auto item: matris)
    {
        if(item->name == n)
            return item;
    }
    return nullptr;
}
#endif // __OPERATOR_OVERLOADED_HPP