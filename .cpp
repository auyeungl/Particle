// Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Matrices.h"
namespace Matrices
{

    ///Add each corresponding element.
     ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        Matrix returnMatrix(a.getRows(), b.getRows());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getRows(); j++)
            {
                returnMatrix(i, j) = a(i, j) + b(i, j);
            }
        }
        return returnMatrix;
    }


    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b);

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b);

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b);

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a);

}
using namespace Matrices;
    int main()
    {

        Matrix test(2, 2);
        Matrix Test2(2, 2);
        Matrix Result(2, 2);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                test(i, j) = 1;
                Test2(i, j) = 2;
            }
        }

        Result = operator+(test, Test2);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << Result(i, j) << " ";
            }
            cout << endl;
        }


        return 0;
    }