template<uint8_t N,
         typename Corps>
Point<N, Corps>::Point() : _value(0)
{
    for(unsigned int i(0); i < N; i++)
        _data[i] = 0;
}

template<uint8_t N,
         typename Corps>
Point<N, Corps>::Point(std::initializer_list<Corps> l, double val) : _value(val)
{
    std::copy(l.begin(), l.end(), _data.begin());
}

template<uint8_t N,
         typename Corps>
void
Point<N, Corps>::set_value(double value)
{
    _value = value;
}

template<uint8_t N,
         typename Corps>
double
Point<N, Corps>::get_value() const
{
    return _value;
}

//
// Operator
//

template<uint8_t N,
         typename Corps>
Point<N, Corps> &
Point<N, Corps>::operator-=(const Point<N, Corps> & o)
{
    return *this = *this - o;
}

template<uint8_t N,
         typename Corps>
Corps&
Point<N, Corps>::operator[](std::size_t i)
{
    return _data[i];
}

//
// Friend
//

template<uint8_t N,
         typename Corps>
Point<N, Corps>
operator-(const Point<N, Corps> & a, const Point<N, Corps> & b)
{
    Point<N, Corps> res;

    for(unsigned int i = 0; i < a._data.size(); i++)
        res[i] = a._data[i] - b._data[i];

    return res;
}

template<uint8_t N,
         typename Corps>
bool
operator==(const Point<N, Corps> & a, const Point<N, Corps> & b)
{
    for(unsigned int i = 0; i < a._data.size(); i++)
        if(a._data[i] != b._data[i])
            return false;

    return true;
}

template<uint8_t N,
         typename Corps>
bool
operator!=(const Point<N, Corps> & a, const Point<N, Corps> & b)
{
    return ! (a == b);
}

template<uint8_t N,
         typename Corps>
std::ostream&
operator<<(std::ostream& flux, const Point<N, Corps> & p)
{
    flux << "[valeur] [" << p._value << "]\n[point ] { ";

    for(unsigned int i = 0; i < N-1; i++)
        flux << p._data[i] << " ; ";

    flux << p._data[N-1] << " }";

    return flux;
}
