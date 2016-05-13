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

    // si calculer_val est à true
    // alors la fonction calcule la valeur barycentrique
    // sinon elle garde la valeur du point
    double inserer(PointNC &, bool calculer_val = true);

    // pour debug
    const SimplexeNC & get_simplexe_englobant() const;
};

#include "pavage.tcc"

#endif
