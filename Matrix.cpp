#include "matrix.h"
#include <sstream>
#include <iomanip>

using namespace std;

namespace BigCPlusPlus_Matrix
{
    string Matrix::IndexException::format_message(int n)
    {
        ostringstream outstr;
        outstr << "Matrix index " << n << " out of range";
        return outstr.str();
    }

    //Excepts from matrix4.cpp

    double& Matrix::operator()(int i, int j)
    {
        if (i < 0 || i >= rows)
            throw Matrix::IndexException(i);
        if (j < 0 || j >= columns)
            throw Matrix::IndexException(i);
        return elements[i * get_columns() + j];
    }
    //...
}

