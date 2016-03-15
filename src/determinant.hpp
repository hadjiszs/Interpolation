#ifndef _DETERMINANT_
#define _DETERMINANT_

template<typename T>
class Determinant {
public:
    T a;
    T b;    
    T getA();
    T getB();
    void swap();
};

#include "determinant.tcc"

#endif
