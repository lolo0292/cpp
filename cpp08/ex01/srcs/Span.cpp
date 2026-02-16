#include "Span.hpp"
#include <algorithm>

Span::Span() : _max(0), _data() {}

Span::Span(unsigned int n) : _max(n), _data()
{
    _data.reserve(n);
}

Span::Span(const Span& other) : _max(other._max), _data(other._data) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _max = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value)
{
    if (_data.size() >= _max)
        throw std::runtime_error("Span is full");
    _data.push_back(value);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    long best = static_cast<long>(tmp[1]) - static_cast<long>(tmp[0]);
    if (best < 0)
        best = -best;

    for (std::size_t i = 1; i < tmp.size(); ++i)
    {
        long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
        if (diff < 0)
            diff = -diff;
        if (diff < best)
            best = diff;
    }
    return static_cast<int>(best);
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

    long diff = static_cast<long>(*maxIt) - static_cast<long>(*minIt);
    if (diff < 0)
        diff = -diff;
    return static_cast<int>(diff);
}

unsigned int Span::size() const
{
    return static_cast<unsigned int>(_data.size());
}

unsigned int Span::capacity() const
{
    return _max;
}
