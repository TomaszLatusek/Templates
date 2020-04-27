#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"
#include "Size.hh"
#include "Complex.hh"

int main()
{
    char type;

    std::cin >> type;

    switch (type)
    {
    case 'r':
        SystemOfLinearEquations<double, SIZE> s1;
        std::cin >> s1;
        std::cout << s1 << std::endl;
        s1.solve();
        s1.showSolution();
        return 0;
        break;
    case 'z':
        SystemOfLinearEquations<Complex, SIZE> s2;
        std::cin >> s2;
        std::cout << s2 << std::endl;
        s2.solve();
        s2.showSolution();
        return 0;        
    default:
        std::cout << "[!] No such option: " << type << std::endl;
        return 1;
        break;
    }
    
}