// 10001st prime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/


bool isPrime(int n) {

	for (size_t i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


int main()
{
	int number = 1;
	int xthPrime = 10001;
	bool xthPrimeFound = false;

	while (!xthPrimeFound)
	{
		number++;
		if (isPrime(number)) {
			xthPrime--;
			if (xthPrime == 0)
				xthPrimeFound = true;
		}
	}
	std::cout << "The number is: " <<   number;
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
