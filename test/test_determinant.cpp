#include "interpol_catch.hpp"
#include "matrice.hpp"

#include <iostream>

TEST_CASE("Test des opérations sur les matrices", "[matrice]")
{
    SECTION("Test calcul de determinant")
    {
        Matrice<2, double> mat1(
            {
                { 9.0 , 3.0 },
                { 1.0 , 6.0 }
            });

        REQUIRE(mat1.det() == 51);

        Matrice<3, double> mat2(
            {
                { -2.0 , 2.0 , -3.0 },
                { -1.0 , 1.0 ,  3.0 },
                {  2.0 , 0.0 , -1.0 }
            });

        REQUIRE(mat2.det() == 18);

        Matrice<4, double> mat3(
            {
                {  2.0 , 5.0 ,  3.0 , 5.0 },
                {  4.0 , 6.0 ,  6.0 , 3.0 },
                { 11.0 , 3.0 ,  2.0 ,-2.0 },
                {  4.0 ,-7.0 ,  9.0 , 3.0 }
            });

        REQUIRE(mat3.det() == 2960);
    }
}
