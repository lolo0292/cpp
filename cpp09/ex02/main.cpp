#include "PmergeMe.hpp"
#include <iostream>
#include <deque>

int main(int argc, char** argv) {
	std::vector<int> input;
	if (!PmergeMe::parseArgs(argc, argv, input)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe::printSequence("Before: ", input);

	// Copy into both containers
	std::vector<int> v = input;
	std::deque<int> d(input.begin(), input.end());

	double tv = PmergeMe::sortVector(v);
	double td = PmergeMe::sortDeque(d);

	PmergeMe::printSequence("After:  ", v);

	std::cout << "Time to process a range of " << v.size()
	          << " elements with std::vector : " << tv << " us" << std::endl;

	std::cout << "Time to process a range of " << d.size()
	          << " elements with std::deque  : " << td << " us" << std::endl;

	return 0;
}
