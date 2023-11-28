const double PI = 3.1415;
#include "Matrices.h"
namespace Matrices
{

    ///Add each corresponding element.
     ///usage:  c = a + b;
     /// 
    
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if ((a.getRows() != b.getRows()) || (a.getCols() != b.getCols()))
        {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix returnMatrix(a.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getCols(); j++)
            {
                returnMatrix(i, j) = a(i, j) + b(i, j);
            }
        }
        return returnMatrix;
    }

    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        a.resize(_rows);
        for (int i = 0; i < _rows; i++)
        {
            a[i].resize(_cols,0);
        }


    }
    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        double sum = 0;
        if (a.getCols() != b.getRows())
        {
            throw runtime_error("Error: dimensions must agree");
        }
        Matrix ReturnMatrix(a.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getCols(); j++)
            {
                sum = 0;
                for (int k = 0; k < a.getCols(); k++)
                {
                    sum += a(i, k) * b(k, j);
                }
                ReturnMatrix(i, j) = sum;
            }
        }
        return ReturnMatrix;
    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b)
    {
        bool ReturnBool;
        if (a.getCols() == b.getCols() && a.getRows() == b.getRows())
        {
            ReturnBool = true;
            for (int i = 0; i < a.getRows() && ReturnBool == true; i++)
            {
                for (int j = 0; j < b.getCols() && ReturnBool == true; j++)
                {
                    if (abs(a(i, j) - b(i, j)) > .001)
                    {
                        ReturnBool = false;
                    }
                }
            }
        }
        else
        {
            ReturnBool = false;
        }
        return ReturnBool;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        bool ReturnBool;
        if (a.getCols() == b.getCols() && a.getRows() == b.getRows())
        {
            ReturnBool = true;
            for (int i = 0; i < a.getRows() && ReturnBool == true; i++)
            {
                for (int j = 0; j < b.getCols() && ReturnBool == true; j++)
                {
                    if (abs(a(i, j) - b(i, j)) > .001)
                    {
                        ReturnBool = false;
                    }
                }
            }
        }
        else
        {
            ReturnBool = false;
        }
        return !(ReturnBool);
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a)
    {

        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << setw(10) << a(i, j) << " ";
            }
            os << endl;
        }
        os << endl;
    return os;
    }
   
    RotationMatrix::RotationMatrix(double theta) : Matrix(2,2)
    { 
        a[0][0] = cos(theta); a[0][1] = -sin(theta);
        a[1][0] = sin(theta); a[1][1] = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
    {
        a[0][0] = scale; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = scale;
    }
    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
    {
        for (int i = 0; i < nCols; i++)
        {
            a[0][i] = xShift;
            a[1][i] = yShift;
        }
    }

}
