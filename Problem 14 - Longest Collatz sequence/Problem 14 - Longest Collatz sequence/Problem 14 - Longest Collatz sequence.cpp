// Problem 14 - Longest Collatz sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
using namespace std;
/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/


bool isInMap(long n, map<long, long> m) {
	map<long, long>::iterator it;

	it = m.find(n);

	if (it == m.end())
		return false;
	else
		return true;


}



long nextElementLength(long seq_number, map<long,long> map) {
	long seq_length = 0;
	long seq_next = 0;


	if (isInMap(seq_number, map)) {
			return map.at(seq_number);
	}
	else {
		if (seq_number % 2 == 0)
		{
			seq_next = seq_number / 2;
			seq_length = 1 + nextElementLength(seq_next, map);
			map.insert(pair<long, long>(seq_number, seq_length));
		}
		else
		{
			seq_next = 3 * seq_number + 1;
			seq_length = nextElementLength(seq_next,map);
			map.insert(pair<long, long>(seq_next, seq_length));
		}
		
	}
	return seq_length;
	
}

long nextElement(long n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return n * 3 + 1;
}


int main()
{
    std::cout << "Hello World!\n";
	bool endSequence = false;
	long start = 2;
	long number = start;
	long range = 15;
	
	long longest_seq = 0;
	long seq_length = 1;
	long seq_number = 1;
	long longest_seq_number = 1;
	std::map<long, long>  map;

	map.insert(pair<long, long>(1, 1));

	for (number; number < range; number++)
	{
			seq_number = number;
		

			//std::cout << seq_number << ", ";
/*
			while (!endSequence)
			{
				

				if (isInMap(seq_number, map)) {
					seq_length = seq_length + map.at(seq_number) - 1;
					seq_number = 1;
				}
				else {
					seq_number = nextElement(seq_number);
					seq_length++;
					//std::cout << seq_number << ", ";
				}


				

				if (seq_number == 1) {
					map.insert(pair<long, long>(number, seq_length));
					endSequence = true;
				}

			}
			//std::cout << std::endl;

			*/

			seq_length = nextElementLength(seq_number, map);


			if (seq_length > longest_seq)
			{
				longest_seq = seq_length;
				longest_seq_number = number;
			}
		
	}
	endSequence = false;
	std::cout << std::endl << "Longest sequence: ";
	std::cout << longest_seq_number << ", ";
	while (!endSequence)
	{
		longest_seq_number = nextElement(longest_seq_number);

		std::cout << longest_seq_number << ", ";

		if (longest_seq_number == 1) {
			endSequence = true;
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
