#ifndef _SIMPLEXE_
#define _SIMPLEXE_

#include <cstdint>
#include <memory>
#include <initializer_list>
#include "point.hpp"
#include "matrice.hpp"

template<uint8_t N, typename Corps>
class Simplexe {
    using SimplexeDC = Simplexe<N, Corps>;
    using PointDC    = Point<N, Corps>;

private:
    std::array<PointDC, N + 1> _list_point;
    std::array<std::unique_ptr<SimplexeDC>, N + 1> _sub_simplexe;

public:
    explicit Simplexe(const std::array<PointDC, N + 1> & );
    Simplexe(std::initializer_list<PointDC>);

    bool contient(const PointDC & ) const;
    bool meme_cote(const PointDC & , const PointDC & ) const;
};

#include "simplexe.tcc"

#endif
