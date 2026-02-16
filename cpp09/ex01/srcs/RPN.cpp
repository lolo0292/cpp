#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isDigitToken(const std::string& tok) {
	// subject: numbers are always < 10 (so a single digit 0..9)
	return (tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9');
}

bool RPN::evaluate(const std::string& expr, long& outResult) const {
	std::stack<long> st;
	std::istringstream iss(expr);
	std::string tok;

	while (iss >> tok) {
		if (isDigitToken(tok)) {
			st.push(static_cast<long>(tok[0] - '0'));
		} else if (tok.size() == 1 && isOperator(tok[0])) {
			if (st.size() < 2)
				return false;

			long b = st.top(); st.pop();
			long a = st.top(); st.pop();
			long res = 0;

			switch (tok[0]) {
				case '+': res = a + b; break;
				case '-': res = a - b; break;
				case '*': res = a * b; break;
				case '/':
					if (b == 0) // division by 0 protection
						return false;
					res = a / b;
					break;
			}
			st.push(res);
		} else {
			// invalid token (e.g. "(1", "12", "1.2", "a")
			return false;
		}
	}

	if (st.size() != 1)
		return false;

	outResult = st.top();
	return true;
}
