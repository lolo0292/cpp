#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <ctime>
#include <climits>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

struct Pair {
	int big;
	int small;
};

static bool isAllDigits(const std::string& s) {
	if (s.empty()) return false;
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

bool PmergeMe::parseArgs(int argc, char** argv, std::vector<int>& out) {
	out.clear();
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; ++i) {
		std::string s(argv[i]);
		if (!isAllDigits(s))
			return false;

		long long x = 0;
		for (std::size_t k = 0; k < s.size(); ++k) {
			x = x * 10 + (s[k] - '0');
			if (x > INT_MAX)
				return false;
		}
		if (x <= 0)
			return false;

		out.push_back(static_cast<int>(x));
	}
	return true;
}

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& v) {
	std::cout << label;
	const std::size_t n = v.size();
	const std::size_t maxPrint = 20;

	for (std::size_t i = 0; i < n && i < maxPrint; ++i) {
		std::cout << v[i];
		if (i + 1 < n && i + 1 < maxPrint)
			std::cout << " ";
	}
	if (n > maxPrint)
		std::cout << " [...]";
	std::cout << std::endl;
}

/* =========================
   Ford-Johnson helpers
   ========================= */

template <typename Cont>
static typename Cont::iterator lowerBound(Cont& c, int value, std::size_t hi) {
	std::size_t lo = 0;
	while (lo < hi) {
		std::size_t mid = lo + (hi - lo) / 2;
		if (c[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return c.begin() + lo;
}

static std::vector<std::size_t> jacobsthalOrder(std::size_t n) {
	std::vector<std::size_t> order;
	if (n == 0) return order;

	std::vector<std::size_t> J;
	J.push_back(0);
	J.push_back(1);
	while (true) {
		std::size_t next = J[J.size() - 1] + 2 * J[J.size() - 2];
		J.push_back(next);
		if (next >= n + 2)
			break;
	}

	std::size_t prev = 1;
	for (std::size_t k = 3; k < J.size(); ++k) {
		std::size_t curr = J[k];
		if (curr > n) curr = n;
		for (std::size_t i = curr; i > prev; --i)
			order.push_back(i);
		prev = curr;
		if (prev == n)
			break;
	}

	std::vector<bool> used(n + 1, false);
	for (std::size_t i = 0; i < order.size(); ++i)
		if (order[i] <= n) used[order[i]] = true;

	for (std::size_t i = 1; i <= n; ++i)
		if (!used[i]) order.push_back(i);

	return order;
}

template <typename Cont>
static void fordJohnsonSort(Cont& input) {
	if (input.size() <= 1)
		return;

	Cont bigs;
	Cont smalls;

	const std::size_t n = input.size();
	const bool hasStraggler = (n % 2 != 0);
	int straggler = 0;

	for (std::size_t i = 0; i + 1 < n; i += 2) {
		int a = input[i];
		int b = input[i + 1];
		if (a <= b) { smalls.push_back(a); bigs.push_back(b); }
		else        { smalls.push_back(b); bigs.push_back(a); }
	}
	if (hasStraggler)
		straggler = input[n - 1];

	// sort bigs recursively
	fordJohnsonSort(bigs);

	// main chain starts with sorted bigs
	Cont mainChain = bigs;

	// rebuild exact original pairs (for matching smalls to sorted bigs)
	std::vector<int> bigsRaw;
	std::vector<int> smallsRaw;
	bigsRaw.reserve(n / 2);
	smallsRaw.reserve(n / 2);

	for (std::size_t i = 0; i + 1 < n; i += 2) {
		int a = input[i];
		int b = input[i + 1];
		if (a <= b) { bigsRaw.push_back(b); smallsRaw.push_back(a); }
		else        { bigsRaw.push_back(a); smallsRaw.push_back(b); }
	}

	std::vector<Pair> pairs;
	pairs.reserve(bigs.size());

	for (std::size_t k = 0; k < bigs.size(); ++k) {
		Pair p;
		p.big = bigs[k];
		p.small = 0;
		pairs.push_back(p);
	}

	// match each sorted big with one unused raw big to get its small
	std::vector<bool> used(bigsRaw.size(), false);
	for (std::size_t k = 0; k < pairs.size(); ++k) {
		for (std::size_t p = 0; p < bigsRaw.size(); ++p) {
			if (!used[p] && bigsRaw[p] == pairs[k].big) {
				used[p] = true;
				pairs[k].small = smallsRaw[p];
				break;
			}
		}
	}

	// pending smalls aligned with sorted bigs
	Cont pending;
	for (std::size_t k = 0; k < pairs.size(); ++k)
		pending.push_back(pairs[k].small);

	// insert first pending at start
	if (!pending.empty())
		mainChain.insert(mainChain.begin(), pending[0]);

	// Jacobsthal insertion order (indices 1..pending.size)
	const std::vector<std::size_t> order = jacobsthalOrder(pending.size());

	for (std::size_t idx = 0; idx < order.size(); ++idx) {
		std::size_t k = order[idx];
		if (k <= 1 || k > pending.size())
			continue;

		int small = pending[k - 1];
		int big = pairs[k - 1].big;

		// find current position of big in mainChain
		std::size_t posBig = 0;
		for (; posBig < mainChain.size(); ++posBig) {
			if (mainChain[posBig] == big)
				break;
		}
		if (posBig > mainChain.size())
			posBig = mainChain.size();

		typename Cont::iterator ins = lowerBound(mainChain, small, posBig);
		mainChain.insert(ins, small);
	}

	// insert straggler into full chain
	if (hasStraggler) {
		typename Cont::iterator ins = lowerBound(mainChain, straggler, mainChain.size());
		mainChain.insert(ins, straggler);
	}

	input = mainChain;
}

static double elapsedMicros(std::clock_t start, std::clock_t end) {
	return (static_cast<double>(end - start) * 1000000.0) / static_cast<double>(CLOCKS_PER_SEC);
}

double PmergeMe::sortVector(std::vector<int>& v) {
	std::clock_t start = std::clock();
	fordJohnsonSort(v);
	std::clock_t end = std::clock();
	return elapsedMicros(start, end);
}

double PmergeMe::sortDeque(std::deque<int>& d) {
	std::clock_t start = std::clock();
	fordJohnsonSort(d);
	std::clock_t end = std::clock();
	return elapsedMicros(start, end);
}
