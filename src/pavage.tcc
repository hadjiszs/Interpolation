template<std::size_t N>
double det(mat<N> matrice) {
  // implementation générique pour une matrice de dimension N
  return 0.0;
}

template<2>
double det(mat<2> m) {
  return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

template<3>
double det(mat<3> m) {
  return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}
