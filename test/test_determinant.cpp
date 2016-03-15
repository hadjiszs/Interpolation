#include "interpol_catch.hpp"
#include "determinant.hpp"

#include <iostream>

TEST_CASE("Test des opérations sur les determinants", "[determinant]")
{
    SECTION("Test création determinant")
    {
        Determinant<int> A;

        std::cout << A.getA() << std::endl;
        std::cout << A.getB() << std::endl;

        A.swap();
        std::cout << "swap" << std::endl;

        std::cout << A.getA() << std::endl;
        std::cout << A.getB() << std::endl;
    }
}
