#include <iostream>
#include "macierz.h"

int main()
{
	// Setting polish characters in console view
	setlocale(LC_ALL, "");

	// Creating object from class Macierz
	Macierz mat;
	Macierz mat2 = mat;
	Macierz mat3;

	// Calling all of the methods
	mat2 += 10;
	mat = mat * 2;
	mat3 = mat;

	std::cout << mat;
	std::cout << mat2;

	mat2 == mat;
	mat += 2;
	mat -= 4;
	mat2 += mat;

	std::cout << mat;
	std::cout << mat2;

	mat3 = mat - mat2;

	std::cout << mat3;

	mat3 -= 5;
	mat3 *= mat2;
	mat3 *= 3;

	mat3.set(0, 1, 23);
	mat3.set(1, 0, 46);

	std::cout << mat3;

	mat3.get(1, 1);
	mat3.transpozycja();

	std::cout << mat3;

	return 0;
}