#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

//nn const peux mod
template <typename T>
void iter(T* array, std::size_t len, void (*f)(T&))
{
	if (!array || !f)
		return;
	for (std::size_t i = 0; i < len; ++i)
		f(array[i]);
}

template <typename T>
void iter(const T* array, std::size_t len, void (*f)(const T&))
{
	if (!array || !f)
		return;
	for (std::size_t i = 0; i < len; ++i)
		f(array[i]);
}

#endif
