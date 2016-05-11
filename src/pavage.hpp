#ifndef _PAVAGE_
#define _PAVAGE_

#include "simplexe.hpp"

template<uint8_t N, typename Corps>
class Pavage {
    using SimplexeNC = Simplexe<N, Corps>;
    using PointNC    = Point<N, Corps>;

private:
    SimplexeNC & _simplexe_englobant;

public:
    Pavage(SimplexeNC &);

    void inserer(const PointNC & );

    // pour debug
    const SimplexeNC & get_simplexe_englobant() const;
};

#include "pavage.tcc"

#endif
