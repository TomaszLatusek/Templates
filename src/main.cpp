#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"
#include "Size.hh"
#include "Complex.hh"

int main()
{
    Matrix<Complex, 3> m;

    std::cin >> m;
    std::cout << m.determinant() << std::endl;
}