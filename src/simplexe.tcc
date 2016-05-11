template<uint8_t N,
         typename Corps>
Simplexe<N, Corps>::Simplexe(const std::array<PointNC, N + 1> & m_list_point, double det)
    : _list_point(m_list_point)
{
    for(unsigned int i = 0; i < N+1; i++)
        _sub_simplexe[i] = nullptr;

    _det = det < 0 ? -det : det;
}

template<uint8_t N,
         typename Corps>
Simplexe<N, Corps>::Simplexe(std::initializer_list<PointNC> l)
{
    std::copy(l.begin(), l.end(), _list_point.begin());

    for(unsigned int i = 0; i < N+1; i++)
        _sub_simplexe[i] = nullptr;
}

/*template<uint8_t N, typename Corps>
Simplexe<N, Corps>::Simplexe(const SimplexeNC & s)
{
    this->_list_point   = s._list_point;
    this->_sub_simplexe = s._sub_simplexe;
}
*/

// Vrai si le point P est dans le simplexe courant
// Faux sinon
template<uint8_t N,
         typename Corps>
bool
Simplexe<N, Corps>::contient(const PointNC & P) const
{
    for(unsigned int i = 0; i < N+1; i++)
    {
        if(! meme_cote(P, _list_point[i]) )
            return false;
    }

    return true;
}

// Vrai si P et R sont de même côté par rapport au N-1 Simplexe faisant face au point R
template<uint8_t N,
         typename Corps>
bool
Simplexe<N, Corps>::meme_cote(const PointNC & P, const PointNC & R) const
{
    std::vector<PointNC> list_point1, list_point2; // N elements

    for(unsigned int i = 0; i < N+1; i++)
    {
        if(_list_point[i] == R)
            continue;

        list_point1.push_back(P - _list_point[i]);
        list_point2.push_back(R - _list_point[i]);
    }

    // matrice N*N elements
    Matrice<N, Corps> mat1(list_point1);
    Matrice<N, Corps> mat2(list_point2);

    return mat1.det() * mat2.det() >= 0;
}

// Vrai si simplexe courant est une feuille (n'a pas de sous simplexe)
// Faux sinon
template<uint8_t N,
         typename Corps>
bool
Simplexe<N, Corps>::est_feuille() const
{
    return _sub_simplexe[0] == nullptr;
}

// parcours des sous simplexes (du plus grand au plus petit
// et renvoie celui qui contient p
template<uint8_t N,
         typename Corps>
Simplexe<N, Corps> &
Simplexe<N, Corps>::get_sub_simplexe(const PointNC & p) const
{
    // TODO: est dans l'ordre croissant par aire
    for(unsigned int i = 0; i < N+1; i++)
    {
        if(_sub_simplexe[i]->contient(p))
            return *_sub_simplexe[i];
    }
}

template<uint8_t N,
         typename Corps>
const std::array<Simplexe<N, Corps>*, N+1> &
    Simplexe<N, Corps>::get_array_simplexe() const
{
    return _sub_simplexe;
}

template<uint8_t N,
         typename Corps>
void
Simplexe<N, Corps>::sous_divise(const PointNC & p)
{
    std::array<PointNC, N+1> list_point_sub_simplexe;
    std::copy(_list_point.begin(), _list_point.end(), list_point_sub_simplexe.begin());

    std::vector<PointNC> l_vec(N);
    Matrice<N, Corps> mat;
    Corps det;

    for(unsigned int i = 0, k = 0; i < N+1; i++)
    {
        std::cout << "i->[" << i << "]" << std::endl;
        list_point_sub_simplexe.at(i) = p;

        // Calcul des vecteurs partant du point p
        for(unsigned j = 1; j < N+1; j++)
            l_vec[j-1] = list_point_sub_simplexe[0] - list_point_sub_simplexe[j];

        mat.set(l_vec);

        std::cout << mat << std::endl;
        std::cout << "\tdeterminant : [" << (det = mat.det()) << "]" << std::endl;

        //
        // Elimination si le simplexe courant a un "volume" vide
        //
        if(det == 0)
        {
            std::cout << "DET 0" << std::endl;
            list_point_sub_simplexe.at(i) = _list_point[i];
            continue;
        }

        // FIXME : Constructeur SimplexeNC doit être generique
        _sub_simplexe[k++] = new SimplexeNC(list_point_sub_simplexe, det);

        list_point_sub_simplexe.at(i) = _list_point.at(i);
    }

    // trie par ordre décroissant du determinant
    std::sort(_sub_simplexe.begin(), _sub_simplexe.end(),
              [&](SimplexeNC* a, SimplexeNC* b) {
                  if(a != nullptr && b != nullptr) return *a > *b;
                  else return false; // FIXME generer exception
              });
}

template<uint8_t N,
         typename Corps>
Point<N, Corps> &
Simplexe<N, Corps>::operator[](std::size_t i)
{
    return _list_point[i];
}

template<uint8_t N,
         typename Corps>
std::ostream&
operator<<(std::ostream& flux, const Simplexe<N, Corps>& s)
{
    flux << "-- Simplexe det [" << s._det << "]" << std::endl;

    // Affichage des points du simplexe courant
    for(unsigned int i = 0; i < N+1; i++)
        flux << "POINT [" << i << "] : " << s._list_point[i] << std::endl;

    flux << "\t-- Sous Simplexes" << std::endl;
    // Affichage des sous simplexes non nullptr
    for(unsigned int i = 0; i < N+1; i++)
        if(s._sub_simplexe[i] != nullptr)
            flux << "\t" << *(s._sub_simplexe[i]);
        else
            flux << "\t Simplexe [" << i << "] vide\n";

    return flux;
}

template<uint8_t N,
         typename Corps>
bool
operator<(const Simplexe<N, Corps> & a, const Simplexe<N, Corps> & b)
{
    return a._det < b._det;
}

template<uint8_t N,
         typename Corps>
bool
operator>(const Simplexe<N, Corps> & a, const Simplexe<N, Corps> & b)
{
    return a._det > b._det;
}

template<uint8_t N,
         typename Corps>
bool
operator<=(const Simplexe<N, Corps> & a, const Simplexe<N, Corps> & b)
{
    return a._det <= b._det;
}

template<uint8_t N,
         typename Corps>
bool
operator>=(const Simplexe<N, Corps> & a, const Simplexe<N, Corps> & b)
{
    return a._det >= b._det;
}
