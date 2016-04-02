#ifndef _DETERMINANT_
#define _DETERMINANT_

template<std::size_t N>
class mat {
private:
  double m[N][N]; // matrice carrée de dimension N

public:
  mat();

};

template<std::size_t N>
double det(mat<N> matrice);

#include "determinant.tcc"

#endif
