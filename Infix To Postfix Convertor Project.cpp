#include "PostFixCalculator.h"

int main()
{
	ifstream inFile;
	ofstream outFile;
	string iFixExp;
	PostFixCalculator converter;

	inFile.open("InfixData.txt");
	if (!inFile.is_open())
	{
		cout << "Could not open file" << endl;
		return 0;
	}

	outFile.open("PostfixData.txt"); 
	while (getline(inFile, iFixExp))
	{
		outFile << "Infix Expression: " << iFixExp << "; " << endl;
		converter.convert(iFixExp);
		outFile << "Postfix Expression: " << converter.getPFixExp() << "\n" << endl;
	}
	inFile.close();
	outFile.close();

	return 0;
}
