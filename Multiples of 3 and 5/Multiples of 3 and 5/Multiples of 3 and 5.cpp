// Multiples of 3 and 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/


int main()
{
   	int sum = 0;

	for (size_t i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0) {
			//std::cout << i << ", ";
			sum += i;
		}
	}
	std::cout << std::endl;
	std::cout << "Sum: " << sum;
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
