#include "interpol_catch.hpp"
#include "pavage.hpp"

#include <iostream>


TEST_CASE("Test pavage", "[pavage]")
{
    //    using PointR3 = Point<3, double>;
    using PointR2 = Point<2, double>;

    SECTION("Test insertion point dans pavage")
    {
        // Triangle ABC dans R2
        PointR2 A({1.0, 1.0}, 1.0);
        PointR2 B({2.0, 3.0}, 5.0);
        PointR2 C({3.0, 1.0}, 7.0);

        Simplexe<2, double> triangle = { A , B , C };
        std::cout << "det simplexe englobant [" << triangle.get_det() << "]" << std::endl;
        Pavage<2, double> pavage(triangle);

        PointR2 p;
        //p.set_value(7.5);
        p[0] = 1.5;
        p[1] = 1.2;
        double po = 0.0;
        std::cout << (po=pavage.inserer(p)) << std::endl;
        p.set_value(po);
        std::cout << "[point] : " <<  p << std::endl;
        //p[1] = 1.0;

        //pavage.inserer(p);
        /*
          std::array<Simplexe<2, double>*, 3> array_simplexe = pavage.get_simplexe_englobant().get_array_simplexe();

          std::cerr << "Nombre de sous simplexe : " << array_simplexe.size() << std::endl;

          for(unsigned int i = 0; i < array_simplexe.size(); i++)
          {
          if(array_simplexe[i] == nullptr)
          {
          //  std::cout << "Simplexe vide" << std::endl;
          continue;
          }

          //std::cout << *array_simplexe[i];
          }
        */
    }
}
