/**
 * \file pavage.hpp
 * \brief Gestionnaire du pavage de l'espace
 */
#ifndef _PAVAGE_
#define _PAVAGE_

#include "simplexe.hpp"

/**
 * \brief classe Pavage
 * \tparam N Dimension de l'espace
 * \tparam Corps corps des coordonnées des points utilisés pour le pavage
 */
template<uint8_t N, typename Corps>
class Pavage {
    using SimplexeNC = Simplexe<N, Corps>;
    using PointNC    = Point<N, Corps>;

private:
    SimplexeNC & _simplexe_englobant;

public:
    /**
     * \brief Constructeur par initialisation
     * \param[in] simplexe_englobant Le simplexe englobant du pavage, il ne sera pas possible d'ajouter des points en dehors de ce simplexe
     */
    Pavage(SimplexeNC & simplexe_englobant);

    /**
     * \brief Insertion d'un point
     * \param[in] p Le point à inserer
     * \param[in] calculer_val Si calculer_val est à true, alors la fonction calcule la valeur barycentrique, sinon elle garde la valeur du point
     */
    double inserer(PointNC & p, bool calculer_val = true);

    /**
     * \brief Getters
     * \return Le simplexe englobant
     */
    const SimplexeNC & get_simplexe_englobant() const;
};

#include "pavage.tcc"

#endif
