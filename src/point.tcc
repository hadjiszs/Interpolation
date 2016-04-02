template<uint8_t N,
         typename Corps>
Point<N, Corps>::Point()
{ }

template<uint8_t N,
         typename Corps>
Point<N, Corps>::Point(std::initializer_list<Corps> l)
{
    std::copy(l.begin(), l.end(), _data.begin());
}
