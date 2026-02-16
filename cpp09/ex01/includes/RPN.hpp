#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	// Evaluate expression like: "8 9 * 9 - 9 - 9 - 4 - 1 +"
	// Returns true on success and sets outResult.
	bool evaluate(const std::string& expr, long& outResult) const;

private:
	static bool isOperator(char c);
	static bool isDigitToken(const std::string& tok);
};

#endif
