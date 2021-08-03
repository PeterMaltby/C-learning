#pragma once
#include <string>
#include <iostream>

/*
FROM : edabit.com
In mathematics a Polydivisible Number (or magic number) is a number in a given number base with digits abcde... that has the following properties:

	Its first digit a is not 0.
	The number formed by its first two digits ab is a multiple of 2.
	The number formed by its first three digits abc is a multiple of 3.
	The number formed by its first four digits abcd is a multiple of 4.
	etc.

Create a function which takes an integer n and returns true if the given number is a Polydivisible Number and false otherwise.
*/

std::string _isPolydivisibleName = "isPolydivisible";
std::string _isPolydivisibleDesc = R"ENDSTR(Checks if number is polydivisible.
A polydivisible number is a number where the first digit is not 0, the first two digits are multiple of 2, first three digits are a multiple of 3, etc
USAGE : isPolydivisible int

EXAMPLE : "isPolydivisible 1232"
OUTPUT : "1232 is polyDivisible"

Peter Maltby 04/08/2021)ENDSTR";

//easy peasy!
bool isPolydivisible(long n) {
	return true;
}


int _isPolydivisible(int argc, std::string* argv) {
	if (argc > 1) {
		int a;
		try {
			a = std::stol(argv[1]);
		}
		catch (const std::invalid_argument&) {
			std::cout << "argument could not be converted to a integer!" << std::endl;
			return 1;
		}
		//do stuff here!
	}
	else std::cout << "NO arguments given, a integer parameter required!" << std::endl;
	return 1;
}
