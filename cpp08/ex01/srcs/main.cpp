#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void subjectExample()
{
    std::cout << "== Subject example ==" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void exceptionsTest()
{
    std::cout << "\n== Exceptions test ==" << std::endl;

    try
    {
        Span sp(1);
        sp.addNumber(42);
        sp.addNumber(43);
    }
    catch (std::exception& e)
    {
        std::cout << "Full: " << e.what() << std::endl;
    }

    try
    {
        Span sp(10);
        sp.addNumber(5);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Too few: " << e.what() << std::endl;
    }
}

static void bigTest()
{
    std::cout << "\n== 10,000 numbers test ==" << std::endl;

    const unsigned int N = 10000;
    Span sp(N);

    std::vector<int> v;
    v.reserve(N);

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (unsigned int i = 0; i < N; ++i)
        v.push_back(std::rand());

    sp.addNumbers(v.begin(), v.end());

    std::cout << "size=" << sp.size() << "/" << sp.capacity() << std::endl;
    std::cout << "shortest=" << sp.shortestSpan() << std::endl;
    std::cout << "longest=" << sp.longestSpan() << std::endl;
}

int main()
{
    subjectExample();
    exceptionsTest();
    bigTest();
    return 0;
}
