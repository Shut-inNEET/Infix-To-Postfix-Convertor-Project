#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

class PostFixCalculator
{
private:
	string pFixExp;

public:
	// Converts infix expression to postfix 
	// Precondition: Valid infix expression passed in iFixExp
	// Postcondition: Postfix expression stored in pFixExp
	void convert(string);

	// Returns precedence of operator
	// Precondition: Valid operator passed in op
	// Postcondition: Returns integer precedence value
	int precedence(char);

	// Returns postfix expression
	// Precondition: None
	// Postcondition: Returns current postfix expression string
	string getPFixExp();
};

