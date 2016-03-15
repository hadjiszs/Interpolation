template<typename T>
T Determinant<T>::getA()
{
    return this->a;
}

template<typename T>
T Determinant<T>::getB()
{
    return this->b;
}

template<typename T>
void Determinant<T>::swap()
{
    T tmp = this->a;
    this->a = this->b;
    this->b = tmp;
}
