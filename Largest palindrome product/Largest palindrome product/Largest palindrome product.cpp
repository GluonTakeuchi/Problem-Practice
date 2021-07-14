// Largest palindrome product.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool isPalindrome(int n) {
	//stringge alakitas
	std::string p = std::to_string(n);
	int length = p.length();
	size_t j;

	//ha paros hosszu
	if (length % 2 == 0) {
		j = 1;
		for (size_t i = 0; i < length/2; i++)
		{
			if (p.at(i) == p.at(length - j))
				j++;
			else
				return false;
		}
		return true;
	}
	//ha paratlan hosszu
	else {
		j = 1;
		for (size_t i = 0; i < (length-1) / 2; i++)
		{
			if (p.at(i) == p.at(length - j))
				j++;
			else
				return false;
		}
		return true;
	}
}

//3 digit-e a szam
bool isThreeDigit(int n) {
	std::string p = std::to_string(n);

	if (p.length() == 3)
		return true;
	else
		return false;
}



int main()
{
	
	//a felso korlat: 999*999=998001, az also korlat: 100*100=10000
	int upperBound = 998001;
	int lowerBound = 10000;
	int number;
	int solution1;
	int solution2;

	//reverse engineer megkozelites: megnezzuk hogy a szam palindrom-e, ha igen akkor azt hogy eloall-e ket 3 digites szam szorzatakent
	for (int number = lowerBound; number < upperBound; number++)
	{
		if (isPalindrome(number)) {
			for (size_t i = 100; i < 999; i++)
			{
				//ha oszthato megnezzuk hogy a masik szam is 3 digites-e
				if(number % i == 0)
					if (isThreeDigit(number / i)) {
						solution1 = i;
						solution2 = number/i;
					}

			}
		}
	}

	std::cout << solution1 << ", " << solution2;


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
