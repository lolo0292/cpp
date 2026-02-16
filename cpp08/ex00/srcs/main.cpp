#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::vector<int>::iterator it1 = easyfind(vec, 10);
        std::cout << "Found in vector: " << *it1 << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 3);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(vec, 99); // doit throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
