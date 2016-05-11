template<uint8_t N,
         typename Corps>
Matrice<N, Corps>::Matrice()
{

}

template<uint8_t N,
         typename Corps>
Matrice<N, Corps>::Matrice(const std::vector<PointNC> & m_mat)
{
    std::copy(m_mat.begin(), m_mat.end(), _mat.begin());
}

template<uint8_t N,
         typename Corps>
Matrice<N, Corps>::Matrice(const std::array<PointNC, N> & m_mat)
{
    for(unsigned int i = 0 ; i < m_mat.size() ; i++)
        _mat[i] = m_mat[i];
}

// Calcul de determinant de la matrice carrée courante
template<uint8_t N,
         typename Corps>
double
Matrice<N, Corps>::det()
{
    int i, j, j1, j2;
    double det = 0.0;
    Matrice<N-1, Corps> m;

    // for each column in sub-matrix
    for(j1 = 0 ; j1 < N ; j1++)
    {
        for (i = 1 ; i < N ; i++)
        {
            j2 = 0;

            for (j = 0 ; j < N ; j++)
            {
                if (j == j1)
                    continue ;

                m._mat[i-1][j2] = _mat[i][j];
                j2++;
            }
        }

        det += pow(-1.0,1.0 + j1 + 1.0) * _mat[0][j1] * m.det();
    }

    return det;
}

// Calcul de determinant de la matrice carrée courante
template<uint8_t N,
         typename Corps>
void
Matrice<N, Corps>::set(const std::vector<PointNC> & m_mat)
{
    for(unsigned int i = 0 ; i < N ; i++)
        _mat[i] = m_mat[i];
}

// FIXME: specialisation partielle
// implementation générique pour
// Matrice<2, Corps> à la place de Matrice<2, double>
template<>
double
Matrice<2, double>::det()
{
    return
        (_mat[0][0] * _mat[1][1]) -
        (_mat[1][0] * _mat[0][1]);
}

template<uint8_t N,
         typename Corps>
std::ostream&
operator<<(std::ostream& flux, const Matrice<N, Corps> & m)
{
    flux << "--[ Matrice ]--" << std::endl;

    for(unsigned int i = 0; i < N; i++)
        flux << m._mat[i] << std::endl;

    flux << "--[ Fin Matrice ]--" << std::endl;

    return flux;
}
