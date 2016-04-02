#include "interpol_catch.hpp"
#include "simplexe.hpp"

#include <iostream>

TEST_CASE("Test de la classe template simplexe", "[simplexe]")
{
    using PointR3 = Point<3, double>;
    using PointR2 = Point<2, double>;

    SECTION("Test si un point 2D est à l'interieur d'un 2-simplexe (triangle)")
    {
        // Triangle ABC dans R2
        PointR2 A = {1.0, 1.0};
        PointR2 B = {2.0, 3.0};
        PointR2 C = {3.0, 1.0};

        Simplexe<2, double> triangle = { A , B , C };

        //PointR2 p;
        /*
            p[0] = 3.0;
            p[1] = 3.0;
            REQUIRE(triangle.contient(p) == false); // en dehors

            p[0] = 2.0;
            p[1] = 2.0;
            REQUIRE(triangle.contient(p) == true); // dedans

            p[0] = 2;
            p[1] = 1;
            REQUIRE(triangle.contient(p) == true); // dedans (sur l'arete)

            p[0] = 3;
            p[1] = 1;
            REQUIRE(triangle.contient(p) == true); // dedans (sur un point)


            // test d'un autre triangle
            A[0] = -0.891282; A[1] = 9.91201;
            B[0] = -1.40823; B[1] = 9.91261;
            C[0] = -1.36963; C[1] = 9.37414;

            p[0] = -1.16961;
            p[1] = 9.83039;
            REQUIRE(triangle.contient(A, B, C, p) == 1); // dedans
        */
    }
}
