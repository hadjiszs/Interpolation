template<uint8_t N, typename Corps>
Simplexe<N, Corps>::Simplexe(const std::array<PointDC, N + 1> & m_list_point)
    : _list_point(m_list_point)
{


}

template<uint8_t N, typename Corps>
Simplexe<N, Corps>::Simplexe(std::initializer_list<PointDC> l)
{
    std::copy(l.begin(), l.end(), _list_point.begin());
}

// Vrai si le point P est dans le simplexe courant
// Faux sinon
template<uint8_t N, typename Corps>
bool
Simplexe<N, Corps>::contient(const PointDC & P) const
{
    for(unsigned int i = 0; i < _list_point.size(); i++)
    {
        if(! meme_cote(P, _list_point[i]) )
            return false;
    }

    return true;
}

// Vrai si P et R sont de même côté par rapport au N-1 Simplexe faisant face au point R
template<uint8_t N, typename Corps>
bool
Simplexe<N, Corps>::meme_cote(const PointDC & P, const PointDC & R) const
{
    std::array<PointDC, N-1> list_point1, list_point2;

    for(unsigned int i = 0; i < _list_point.size(); i++)
    {
        if(_list_point[i] == R)
            continue;

        list_point1[i] = P - _list_point[i];
        list_point2[i] = R - _list_point[i];
    }

    Matrice<N-1, Corps> mat1(list_point1);
    Matrice<N-1, Corps> mat2(list_point2);

    return mat1.det() * mat2.det() > 0;
}
