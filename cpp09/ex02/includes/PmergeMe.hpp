#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// parse argv[1..] into out (returns false on error)
	static bool parseArgs(int argc, char** argv, std::vector<int>& out);

	// sort using Ford-Johnson on vector/deque (returns elapsed microseconds)
	static double sortVector(std::vector<int>& v);
	static double sortDeque(std::deque<int>& d);

	// helper display (used by main)
	static void printSequence(const std::string& label, const std::vector<int>& v);

private:
};

#endif
