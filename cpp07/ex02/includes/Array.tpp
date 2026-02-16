#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (_size == 0)
		return;
	_data = new T[_size]; // default-initialized
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete[] _data;
	_data = NULL;
	_size = other._size;

	if (_size == 0)
		return *this;

	_data = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBounds();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBounds();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Array: index out of bounds";
}

#endif
