/**
 * \file simplexe.hpp
 * \brief Gère les manipulations des simplexes
 */
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

/**
 * \brief classe template Simplexe
 * \tparam N Dimension de la matrice
 * \tparam Corps Corps des élements de la matrice
 */
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

    /**
     * \brief Constructeur par initialisation
     * \param[in] list_point liste de N+1 points de dimension N formant le simplexe
     */
    Simplexe(const std::array<PointNC, N + 1> & list_point);

    /**
     * \brief Constructeur par initialisation
     * \param[in] init_list liste des N+1 points par liste d'initialisation
     */
    Simplexe(std::initializer_list<PointNC> init_list);

    /**
     * \brief Met à jour la valeur du "volume" du simplexe (valeur strictement positive)
     */
    void update_det();

    /**
     * \brief Prédicat permettant de savoir si un point est contenue dans le simplexe courant
     * \param[in] p le point à tester
     */
    bool contient(const PointNC & p ) const;

    /**
     * \brief Prédicat permettant de savoir si deux points sont du même coté par rapport au simplexe
     */
    bool meme_cote(const PointNC & a, const PointNC & b) const;

    /**
     * \brief Prédicat permettant de savoir si le simplexe courant est une feuille (i.e qui n'a pas de sous simplexe)
     */
    bool est_feuille() const;

    /**
     * \brief Recuperation du sous simplexe contenant un point spécifié
     * \param[in] p le point
     * \return le sous simplexe contenant le point p
     */
    SimplexeNC & get_sub_simplexe(const PointNC & p) const;

    /**
     * \brief Recuperation du sous simplexe contenant un point spécifié
     * \param[in] p le point
     * \return le sous simplexe contenant le point p
     */
    SimplexeNC * get_sub_simplexe(unsigned int) const;

    /**
     * \brief Getter "volume" du simplexe, pour un 2-simplexe ABC, on retourne \f$\det(AB, AC)\f$
     * \return le determinant
     */
    double get_det() const;

    /**
     * \brief Sous divise le simplexe courant par insertion du point p
     * \param[in] p le point à inserer dans le simplexe courant
     * \param[in] cval flag, si est à true, alors on calcule la valeur associé au point p en fonction des points du simplexe, sinon garde la valeur du point
     * \return le determinant
     */
    double sous_divise(PointNC & p, bool cval = true);

    /**
     * \brief Getter du tableau des sous simplexe
     * \return le tableau des sous simplexe
     */
    const std::array<SimplexeNC*, N+1> & get_array_simplexe() const;

    //
    // Surcharge d'operateur
    //
    PointNC & operator[](std::size_t);

    friend std::ostream& operator<< <>(std::ostream& flux, const SimplexeNC &);
    friend bool          operator<  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator>  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator<=  <>(const SimplexeNC &, const SimplexeNC &);
    friend bool          operator>=  <>(const SimplexeNC &, const SimplexeNC &);
};

#include "simplexe.tcc"

#endif
