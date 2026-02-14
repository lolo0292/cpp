#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap
template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// min
template <typename T>
T min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

// max
template <typename T>
T max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
