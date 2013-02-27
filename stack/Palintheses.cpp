//Palintheses.cpp
//Includes Parentheses, a parentheses checker, and Palindrome, a palindrome builder.
//Charlie Severson

#include <iostream>
#include <stdlib.h>
#include "TemplateClass.h"

using  namespace std;
			
//==============================================================================
// Parentheses 
//==============================================================================
bool Parentheses(string input)							//Parentheses is a parentheses checker, checking to make sure every parentheses, ([{, has a complement, }]). Mismatched, ([)], and open, (, parentheses are illegal. 
	{
	
	Stack<char> left;							//We define parentheses without complements as "left", meaning that they are the left parentheses, while their complement, if it exists, is right. 
	int variable;								//variable is synonymous with temporary variable

	for (variable = 0; variable < input.length(); variable++)		//variable is assigned the iterative value of the for loop. This is the outer loop, so once this loop terminates, the program moves on to the next function.
		{
		
		if ((input[variable] =='(') || (input[variable] == '[') || (input[variable] == '{'))	
			{							//If variable is assigned as a left parentheses, then it is pushed unto the stack. If not, move onto the else if statement.
			left.push(input[variable]);
			}
			
		else if ((input[variable] ==')') || (input[variable] == ']') || (input[variable] == '}'))
			{							//If variable is assigned as a right parentheses . . .
					
			if (left.isEmpty() == true)				//. . . and the stack is empty, then the right parentheses has no complement, and thus the checker returns False.
				{
				return false;
				}
				
			char temp = left.pop();					//temp is defined as the temporary value of the topmost variable on the stack
			
			if ((temp == '(' && input[variable] ==')')||
				(temp == '[' && input[variable] ==']')||
				(temp == '{' && input[variable] =='}'))
				{
				}						// . . . and the topmost variable on the stack is its complement, then do nothing. 
			else
				{						// . . . and the topmost variable on the stack is not its complement, then by simply logic we can conclude that not all the parentheses match up and thus it is False
				return false;
				}
			}
		}
		
	if (left.isEmpty() == true)						//If the for loop completes and the stack is empty, then either there were no parentheses in the string, or all parentheses had complements. Either way, it is True!
		{

		return true;							//On the other hand, if there is still parentheses in the stack, they must not have a complement, thus it is False.
		}
	//cout << "___" << endl;	
	return false;							
	
	}
//==============================================================================
// Palindrome
//==============================================================================
void Palindrome(string input)							//Palindrome takes a string of length n, and produce a string of length 2n, with one half in forward order, and the latter half in reverse order. 
	{
	
	Stack<char> current, output;						//initialize the stacks current and output. We'll discuss their purpose later . . .
	int variable;								//variable is synonymous with temporary variable
	
	for (variable = 0; variable < input.length(); variable++)		//variable is assigned the iterative value of the for loop. This is the outer loop, so once this loop terminates, the program moves on to the next function.
		{
		current.push(input[variable]);					//current is a stack which we will use to reverse the string input by the very nature of a stack. How clever!
		output.push(input[variable]);					//output is a stack which contains the final Palindrome. We load the forward part of the Palindrome (backwards in you're in Australia) into the stack. 
		}
		
	while (current.isEmpty() != 1)						//while the stack current is not empty . . .
		{
		output.push(current.pop());					//. . . load its contents into output. Note bene: because we are popping, and because a stack is LIFO, this reverses the string!
		}
		
	cout << output << endl;							//Now output contains both the forward and the backward version of the string. Let's print it!
	
	}

int main(void)
	{
	Stack<char> print;
	
	bool test1 = Parentheses("({})}}");
	bool test2 = Parentheses("({{}[]})([])");
	
	bool a = Parentheses("Ev(erything starts so)mewhere, althou)gh many physicists disa(gree.");
	bool b = Parentheses("The ye(ar that Buttercup wa)[s born, the most bea()()utiful wo[]man in the world was a Fre[nch scullery maid named Anne{}tte.");
	bool c = Parentheses("(In a hole in the ground there lived a [ho{bb}it.]) {Not a nasty, dirty, wet hole,} filled with the endsof worms and an oozy smell, [nor yet a dry, {bare}, sandy hole] with nothing in it to [sit down on or eat]: it was a hobbit-hole, and that means [{comfort.}]");
	
	cout << "\n" << endl;
	cout << "test1 should be false: "<< test1 << endl;
	cout << "test2 should be true: "<< test2 << endl;
	cout << "a should be false: "<< a << endl;
	cout << "b should be false: "<< b << endl;
	cout << "c should be true: " << c << endl;
	cout << "\n" << endl;
		
	Palindrome("Test");
	cout << "\n" << endl;
	Palindrome("Call me Ishmael");
	cout << "\n" << endl;
	Palindrome("racecar");
	cout << "\n" << endl;
	Palindrome("hello");
	
	
	return 0;
	}
