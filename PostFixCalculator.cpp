#include "PostFixCalculator.h"

void PostFixCalculator::convert(string iFixExp)
{
	stack<char> opStack;
    pFixExp = "";

    for (char c : iFixExp) 
    {
        if (isalpha(c))
        {
            pFixExp += c;
        }
        else if (c == '(') 
        {
            opStack.push(c);
        }
        else if (c == ')') 
        {
            if (!opStack.empty())
            {
                while (opStack.top() != '(')
                {
                    pFixExp += opStack.top();
                    opStack.pop(); 
                }
                opStack.pop();
            }  
        }
        else if (c == ' ') 
        {
            continue;
        }
        else 
        {
            while (!opStack.empty() && precedence(c) <= precedence(opStack.top())) 
            {
                pFixExp += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) 
    {
        pFixExp += opStack.top();
        opStack.pop();
    }
}

int PostFixCalculator::precedence(char op) 
{
    if (op == '+' || op == '-') 
    {
        return 1;
    }
    else if (op == '*' || op == '/') 
    {
        return 2;
    }
    else 
    {
        return 0;
    }
}

string PostFixCalculator::getPFixExp() 
{
    return pFixExp;
}