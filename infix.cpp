#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prec(char a)
{
if ((a == '*') || (a=='/')) {return 4;}
else if ((a == '+') || (a=='-')) {return 3;}
else {return 0;}
}

// convert to postfix using passed by value string, returning a string.
string infix_to_postfix(string infix)
{
	stack<char> stk;
	string postfix = "";
	string operators = "*/+-";
	string non_operand = "()*/-+";
	for (char c : infix)
	{
		// if c is an operand, concat to postexp:
		if (non_operand.find(c) == string::npos) {postfix.push_back(c);} // if operand, concat to postfix
		else if (c == '(') {stk.push(c);} // if (, push onto stack
		else if (c == ')') // if ), push and concat from stack and concattenating until a ( is seen.
			{
			

			if (!stk.empty())
				{// while loop
				while (stk.top() != '(')
					{
					postfix.push_back(stk.top()); // append top of stack
					stk.pop(); // remove top
					}
				stk.pop(); // pop the remaining '('
				}
			}
		else if (operators.find(c) != string::npos) // then c is an operator
		    {
			// while stack not empty and token not higher precidence than stack top
			while(!(stk.size() == 0) && (stk.top()!= ('(' || ')')) && (!(prec(c) > prec(stk.top()))))
			{
			    // pop from stack and concat to postfix.
			    postfix.push_back(stk.top());
			    stk.pop();
				
			}
			stk.push(c);
		    }
	}

	while (!(stk.size() == 0))
		{
		postfix.push_back(stk.top());
		stk.pop();
		}
		
	
return postfix;
}


// define main
int main()
{
string userinp = "";
cout << "enter an infix equation, This calculator is able to handle '*','/','-','+','(' and ')'" << endl;

// get user input as a string.
cin >> userinp;

// convert to postfix:
string postfix = infix_to_postfix(userinp);
cout << "here is the expression you entered as a postfix expression: " << postfix << endl;





return 0;
}

