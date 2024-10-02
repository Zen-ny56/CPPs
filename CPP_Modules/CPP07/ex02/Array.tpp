
template <typename T>
Array<T>::Array() :data(NULL), _size(0)
{
	std::cout << "Array default constructor has been called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) :data(new T[n]) ,_size(n)
{
	std::cout << "Array parametirized constructor has been called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& copy) :data(NULL) ,_size(0)
{
	*this = copy;
	std::cout << "Copy constructor has been called" << std::endl;

}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        // Temporary buffer for the new data to ensure exception safety
        T* newData = NULL;

        if (copy._size > 0)
        {
            newData = new T[copy._size];
            for (unsigned int i = 0; i < copy._size; ++i)
                newData[i] = copy.data[i];
        }

        // Deallocate the old data and assign the new data
        delete[] data;
        data = newData;
        _size = copy._size;
    }

    std::cout << "Array copy assignment operator has been called" << std::endl;

    return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
	std::cout << "Array deconstructor has been called" << std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
    return (data[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
const char* Array<T>::OutOfBounds::what(void) const throw()
{
    return "Array index out of bounds";
}