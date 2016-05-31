/**
 * \file point.hpp
 * \brief Gère les points de l'espace
 */
#ifndef _POINT_
#define _POINT_

#include <array>
#include <cstdlib> // for std::size_t
#include <initializer_list>
#include <iostream>
#include <ostream>

template<uint8_t N,
         typename Corps>
class Point;

//
// Surcharge d'operateurs
//

template<uint8_t N,
         typename Corps>
bool operator==(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool operator!=(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
Point<N, Corps> operator-(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
std::ostream& operator<<(std::ostream &, const Point<N, Corps> &);

//
// Template class Point
//

/**
 * \brief classe template point
 * \tparam N Dimension de la matrice
 * \tparam Corps Corps des élements de la matrice
 */
template<uint8_t N,
         typename Corps>
class Point {
public:
    using PointNC = Point<N, Corps>;

private:
    std::array<Corps, N> _data;
    double _value;

public:
    Point();

    /**
     * \brief Constructeur par initialisation
     * \param[in] l liste des N coordonnées du point
     * \param[in] val valeur associée au point
     */
    Point(std::initializer_list<Corps> l, double val = 0.0);

    /**
     * \brief Setter de la valeur associé au point
     * \param[in] val nouvelle valeur
     */
    void   set_value(double val);

    /**
     * \brief Getter de la valeur associé au point
     * \param[out] valeur associée au point
     */
    double get_value() const;

    //
    // Surcharge des operateurs
    //
    Corps&         operator[](std::size_t);
    PointNC&       operator-=(const PointNC &);

    friend bool           operator== <>(const PointNC &, const PointNC &);
    friend bool           operator!= <>(const PointNC &, const PointNC &);
    friend PointNC        operator-  <>(const PointNC &, const PointNC &);
    friend std::ostream & operator<< <>(std::ostream &, const PointNC & p);
};

//
// Template implementation
//

#include "point.tcc"

#endif
