// Special Pythagorean triplet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;
/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

bool isSquare(long long  n2) {
	long long  n = sqrt(n2);
	if (n*n == n2)
		return true;
	else
		return false;
}


bool isTriplet(long long  a2, long long  b2) {
	long long  a = 0;
	long long  b = 0;
	if (isSquare(a2))
		a = sqrt(a2);
	else
		return false;
	if (isSquare(b2))
		b = sqrt(b2);
	else
		return false;
	
	long long  c2 = a2 + b2;
	if (isSquare(c2))
		return true;		
	else
		return false;
}

int main()
{
	long long sum = 1000;
	

	/*
	* Rossz megoldas :(
	* long long range = sum * sum;
	* 
	for (long long  a2 = 4; a2 < range; a2++)
	{
		for (long long  b2 = 4; b2 < range; b2++)
		{
			if (isTriplet(a2, b2)) {
				
				long long  c2 = a2 + b2;
				long long  a = sqrt(a2);
				long long  b = sqrt(b2);
				long long  c = sqrt(c2);
				if (a + b + c == sum) {
					std::cout << "a: " << a << " b: " << b << " c: " << c << endl;
					std::cout << "Product: " << a * b * c << endl;
					
				}
			}
		}
	}
	*/
	for (long long a = 1; a < sum; a++)
	{
		for (long long b = 1; b < sum; b++)
		{
			long long c = sqrt(a * a + b * b);
			if (a + b + c == sum) {
				long long a2 = a * a;
				long long b2 = b * b;
				if (isTriplet(a2, b2)) {
					std::cout << "a: " << a << " b: " << b << " c: " << c << endl;
					std::cout << "Product: " << a * b * c << endl;
				}
			}
		}
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
