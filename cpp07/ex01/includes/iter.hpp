#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// version non-const: permet de modifier les éléments si f prend T&
template <typename T>
void iter(T* array, std::size_t len, void (*f)(T&))
{
	if (!array || !f)
		return;
	for (std::size_t i = 0; i < len; ++i)
		f(array[i]);
}

// version const: supporte les tableaux const + les fonctions qui prennent const T&
template <typename T>
void iter(const T* array, std::size_t len, void (*f)(const T&))
{
	if (!array || !f)
		return;
	for (std::size_t i = 0; i < len; ++i)
		f(array[i]);
}

#endif
