// Smallest multiple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

bool isDivisible(int number, int range) {
	int divNum = 0;
	for (size_t i = 1; i < range + 1; i++)
	{
		if (number % i == 0)
			divNum++;
		else
			return false;
	}
	if (divNum != range)
		return false;
	else
		return true;
}

int main()
{
  	int range = 20;
	int n = 1;

	while (true)
	{
		if (isDivisible(n, range)) {
			std::cout << "The number is: " << n;
			break;
		}
		else
			n++;
	}	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
