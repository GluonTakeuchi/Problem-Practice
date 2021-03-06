// Even Fibonacci numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/


int main()
{
   	int fibo1 = 0;
	int fibo2 = 1;
	int f = 0;
	int sum = 0;

	for (size_t i = 0; f < 4000000; i++)
	{
		f = fibo1 + fibo2;
		if (f % 2 == 0)
			sum += f;
		//std::cout << f << ", ";
		fibo1 = fibo2;
		fibo2 = f;
	}

	std::cout << std::endl;
	std::cout << sum;
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
