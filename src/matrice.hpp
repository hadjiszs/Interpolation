#ifndef _MATRICE_
#define _MATRICE_

#include <cstdint>
#include <array>
#include "point.hpp"


template<uint8_t N,
         typename Corps>
class Matrice;

template<uint8_t N,
         typename Corps>
std::ostream& operator<<(std::ostream &, const Matrice<N, Corps> &);


// Matrice carrée N*N
template<uint8_t N,
         typename Corps>
class Matrice {
    using PointNC = Point<N, Corps>;

public:
    std::array<PointNC, N> _mat;

    // TODO: Rendre le constructeur générique sur le conteneur en parametre
    Matrice();
    Matrice(const std::vector<PointNC> & );
    Matrice(const std::array<PointNC, N> & );

    void set(const std::vector<PointNC> & );
    double det();
    friend std::ostream & operator<< <>(std::ostream &, const Matrice<N, Corps> & m);
};

#include "matrice.tcc"

#endif
