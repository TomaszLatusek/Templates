#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"
#include "Size.hh"

int main()
{
    Vector<double, SIZE> v1, v2;
    Matrix<double, SIZE> m1, m2;
    SystemOfLinearEquations<double, 3> s;

    std::cin >> v1 >> m1;
    std::cout << v1 << m1 << m1[1] << m1.determinant() << std::endl << m1*v1 << std::endl;

}