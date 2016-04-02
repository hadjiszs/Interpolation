#ifndef _MATRICE_
#define _MATRICE_

#include <cstdint>
#include <array>
#include "point.hpp"

// Matrice carrée N*N
template<uint8_t N, typename Corps>
class Matrice {
    using PointDC = Point<N, Corps>;

private:
    std::array<PointDC, N> _lignes;

public:
    explicit Matrice(const std::array<PointDC, N> & );

    double det();
};

#include "matrice.tcc"

#endif
