#ifndef _SIMPLEXE_
#define _SIMPLEXE_

#include <cstdint>
#include <memory>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <algorithm>

#include "point.hpp"
#include "matrice.hpp"

template<uint8_t N,
         typename Corps>
class Simplexe;

//
// Surcharge d'operateurs
//

template<uint8_t N,
         typename Corps>
std::ostream& operator<<(std::ostream &, const Simplexe<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool         operator<(const Simplexe<N, Corps> &, const Simplexe<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool         operator>(const Simplexe<N, Corps> &, const Simplexe<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool         operator<=(const Simplexe<N, Corps> &, const Simplexe<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool         operator>=(const Simplexe<N, Corps> &, const Simplexe<N, Corps> &);

//
// Template class Simplexe
//

template<uint8_t N,
         typename Corps>
class Simplexe {
    using SimplexeNC = Simplexe<N, Corps>;
    using PointNC    = Point<N, Corps>;

private:
    std::array<PointNC, N + 1> _list_point;
    std::array<SimplexeNC*, N + 1> _sub_simplexe;
    double _det;

public:
    Simplexe();
    ~Simplexe();

    Simplexe(const std::array<PointNC, N + 1> &);
    Simplexe(std::initializer_list<PointNC>);
    //    Simplexe(const SimplexeNC &);

    void update_det();
    bool contient(const PointNC & ) const;
    bool meme_cote(const PointNC & , const PointNC & ) const;
    bool est_feuille() const;

    SimplexeNC & get_sub_simplexe(const PointNC & ) const;
    SimplexeNC * get_sub_simplexe(unsigned int) const;
    double get_det() const;
    double sous_divise(PointNC &, bool cval = true);
    PointNC & operator[](std::size_t);

    // pour debug
    const std::array<SimplexeNC*, N+1> & get_array_simplexe() const;

    friend std::ostream& operator<< <>(std::ostream& flux, const SimplexeNC &);
    friend bool          operator<  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator>  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator<=  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator>=  <>(const SimplexeNC &, const SimplexeNC &);
};

#include "simplexe.tcc"

#endif
