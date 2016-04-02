template<uint8_t N, typename Corps>
Matrice<N, Corps>::Matrice(const std::array<PointDC, N> & m_lignes)
    : _lignes(m_lignes)
{

}

// Calcul de determinant de la matrice carrée courante
template<uint8_t N, typename Corps>
double
Matrice<N, Corps>::det()
{
    double res = 0.0;

    return res;
}
