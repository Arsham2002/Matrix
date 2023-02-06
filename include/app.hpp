#
#ifndef __APP_HPP
#define __APP_HPP

#include "Matrix.hpp"
using namespace std;
class App
{
    private:
        string command;
        bool miss_operand;//It is correct if the user gives an incomplete command
        vector<Matrix*> user_matris;//User matrices

    public:
        ~App();//destructor frees the memory taken by the vector
        bool run(string);//It recognizes the command and returns true if it is an exit

        /*The following functions separate the command and
          call their corresponding function in the matrix class*/
        void add_matrix_command();
        /*To better understand the following functions, first read the   
          implementation and comments of the above function*/
        void show_command();
        void is_diagonal_command();
        void is_lower_triangular_command();
        void is_upper_triangular_command();
        void is_triangular_command();
        void is_identity_command();
        void is_skew_symmetric_command();
        void is_normal_symmetric_command();
        void is_symmetric_command();
        void delete_command();
        void change_command();
        void inverse_command();
};


#endif // __APP_HPP
