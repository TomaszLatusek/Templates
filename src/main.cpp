#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"
#include "Size.hh"
#include "Complex.hh"

int main()
{
    char type;

    std::cin >> type; /* wczytaj znak opcji 'r' lub 'z' */

    switch (type)
    {
    case 'r': /* rzeczywisty uklad */
        SystemOfLinearEquations<double, SIZE> s1;
        std::cin >> s1; /* wczytaj uklad */
        std::cout << s1 << std::endl; /* wypisz uklad */
        s1.solve();
        s1.showSolution();
        s1.countErrorVector();
        s1.showErrorVector();
        return 0;
        break;
    case 'z': /* zespolony uklad */
        SystemOfLinearEquations<Complex, SIZE> s2;
        std::cin >> s2; /* wczytaj uklad */
        std::cout << s2 << std::endl; /* wypisz uklad */
        s2.solve();
        s2.showSolution();
        s2.countErrorVector();
        s2.showErrorVector();
        return 0;
    default: /* brak 'r' lub 'z' na poczatku */
        std::cout << "[!] No such option: " << type << std::endl;
        return 1;
        break;
    }

    /*********************************************************
     *************** Modyfikacja na zajeciach ****************
     *********************************************************/
     /* nalezy odkomentowac */
     
    // double error = 0.000001;
    // Complex c;
    // Matrix<double, 2> m;

    // std::cin >> c;
    // double magnitude = abs(c) * abs(c);

    // m(0, 0) = m(1, 1) = c.re;
    // m(0, 1) = -c.im;
    // m(1, 0) = c.im;

    // if (std::abs(magnitude - m.determinant()) < error)
    // {
    //     std::cout << "magnitude = determinant = " << magnitude << std::endl;
    // }
    // else
    // {
    //     std::cout << "Zonk:/" << std::endl;
    // }

    return 0;
}