#ifndef _POINT_
#define _POINT_

#include <array>
#include <initializer_list>

template<uint8_t N,
         typename Corps>
class Point {
private:
    std::array<Corps, N> _data;

public:
    Point();
    Point(std::initializer_list<Corps> l);
};

#include "point.tcc"

#endif
