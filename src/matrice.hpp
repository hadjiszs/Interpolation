/**
 * \file matrice.hpp
 * \brief Gère les manipulations de base sur les matrices carrées
 */
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

/**
 * \brief classe template matrice
 * \tparam N Dimension de la matrice
 * \tparam Corps Corps des élements de la matrice
 */
template<uint8_t N,
         typename Corps>
class Matrice {
    using PointNC = Point<N, Corps>;

public:
    std::array<PointNC, N> _mat;
    
    // TODO: Rendre le constructeur générique sur le conteneur en parametre
    Matrice();
    
    /**
     * \brief Constructeur par initialisation
     * \param[in] list_point liste de N point de dimension N
     */
    Matrice(const std::vector<PointNC> & list_point);
    
    /**
     * \brief Constructeur par initialisation
     * \param[in] list_point liste de N point de dimension N
     */
    Matrice(const std::array<PointNC, N> & list_point);

    /**
     * \brief Setter de la liste de point
     * \param[in] list_point liste de N point de dimension N
     */
    void set(const std::vector<PointNC> & list_point);
    
    /**
     * \brief Calcul et met à jour le determinant
     * \return determinant
     */
    double det();
    
    /**
     * \brief Surcharge de l'operator<< pour afficher une matrice
     */
    friend std::ostream & operator<< <>(std::ostream &, const Matrice<N, Corps> & m);
};

#include "matrice.tcc"

#endif
