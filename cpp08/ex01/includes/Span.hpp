#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <cstddef>

class Span
{
private:
    unsigned int        _max;
    std::vector<int>    _data;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addNumbers(InputIt first, InputIt last)
    {
        std::size_t dist = 0;
        for (InputIt it = first; it != last; ++it)
            ++dist;

        if (_data.size() + dist > _max)
            throw std::runtime_error("Span is full");

        for (InputIt it = first; it != last; ++it)
            _data.push_back(*it);
    }

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;
};

#endif
