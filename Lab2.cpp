//Name: Andrew Kinney
//Title: Program Lab 2
//Description: Writing recursive and iterative functions
//Date: 2.8.2022
//Course: Data Structures
//File: Main

#include <iostream>

using namespace std;

int factorialRecursive(int n, int product);
int factorialIterative(int n);
void printCharsRecursive(char start, char end);
void printCharsIterative(char start, char end);

int main()
{
    int num = 6;
    //Problem 1
    cout << "Factorial of " << num << ": " << factorialRecursive(num, 1) << " (Recursive)" << endl;
    
    //Problem 2
    cout << "Factorial of " << num << ": " << factorialIterative(num) << " (Iterative)" << endl << endl;
    
    char start = 'b', end = 'g';
    //Problem 3
    cout << "Range from " << start << " to " << end << " is: ";  
    printCharsRecursive(start, end);
    cout << " (Recursive)" << endl;
    
    //Problem 4
    cout << "Range from " << start << " to " << end << " is: ";  
    printCharsIterative(start, end);
    cout << " (Iterative)";
    
    return 0;
}

//Problem 1
int factorialRecursive(int n, int product)
{
    if(n > 1)
        return factorialRecursive(--n, product*n);
    else
        return product;
}

//Problem 2
int factorialIterative(int n)
{
    int product = n;
    
    for(int i = n; i > 1; i--)
        product *= (i-1);
    
    return product;
}

//Problem 3
void printCharsRecursive(char start, char end)
{
	if(start != end+1)
	{
	    cout << start;
	    printCharsRecursive(++start, end);
	}
	    
    else
        return;
}

//Problem 4
void printCharsIterative(char start, char end)
{
	while(start != end+1)
		cout << start++;
}











