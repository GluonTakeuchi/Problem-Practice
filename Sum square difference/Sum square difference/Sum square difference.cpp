// Sum square difference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/

int main()
{
	int xNumbers = 20;
	int sumOfSquare = 0;
	int squareofSum = 0;

	for (size_t i = 1; i < xNumbers + 1; i++)
	{
		sumOfSquare += i * i;

		squareofSum += i;
	}
	squareofSum = squareofSum * squareofSum;

	std::cout << sumOfSquare << ", " << squareofSum << std::endl;
	std::cout << "Difference:" << (squareofSum - sumOfSquare);

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
