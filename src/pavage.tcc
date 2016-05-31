/**
 * \file pavage.tcc
 * \brief Implementation de pavage.hpp
 */
template<uint8_t N, typename Corps>
Pavage<N, Corps>::Pavage(SimplexeNC & m_simplexe_englobant)
    : _simplexe_englobant(m_simplexe_englobant)
{

}

template<uint8_t N, typename Corps>
double
Pavage<N, Corps>::inserer(PointNC & p, bool calculer_val)
{
    if( ! _simplexe_englobant.contient(p))
    {
        std::cerr << "Le point " // << p <<
                  << " n'est pas dans le simplexe englobant " << std::endl;
        return 0.0;
    }

    SimplexeNC* simplexe_courant = &_simplexe_englobant;

    // recuperation du simplexe feuille contenant p
    // recherche logarithmique
    while( ! simplexe_courant->est_feuille() )
        simplexe_courant = &(simplexe_courant->get_sub_simplexe(p));
    
    // subdivision du simplexe_courant
    return simplexe_courant->sous_divise(p, calculer_val);
}

template<uint8_t N, typename Corps>
const Simplexe<N, Corps> &
Pavage<N, Corps>::get_simplexe_englobant() const
{
    return _simplexe_englobant;
}
