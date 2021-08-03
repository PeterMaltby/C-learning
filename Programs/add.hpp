#pragma once
#include <string>
#include <iostream>

//Create a function that takes two numbers as arguments and return their sum.

std::string _addName = "add";
std::string _addDesc = R"ENDSTR(Adds two integers together and prints the result.
USAGE : add int int

EXAMPLE : "add 2 3"
OUTPUT : "2 + 3 = 5"

Peter Maltby 04/08/2021)ENDSTR";

//easy peasy!
int add(const int& a,const int& b) { return a + b; }


int _add(int argc, std::string* argv) {
	if (argc > 2) {
		int a, b;
		try {
			a = std::stoi(argv[1]);
			b = std::stoi(argv[2]);
		}
		catch (const std::invalid_argument&) {
			std::cout << "arguments could not be converted to a integer!" << std::endl;
			return 1;
		}
		std::cout << a << " + " << b << " = " << add(a , b) << std::endl;
	}
	else std::cout << "ONLY " << argc-1 << " arguments given, 2 integer parameters required!" << std::endl;
	return 1;
}
