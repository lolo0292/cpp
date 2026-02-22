#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array& other);
	~Array(void);

	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size(void) const;

	class OutOfBounds : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	T*            _data;
	unsigned int  _size;
};

#include "Array.tpp"

#endif
