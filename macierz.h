#ifndef _MACIERZ_H_
#define _MACIERZ_H_

#include <string>

class Macierz
{
private:
	double matrix[2][2];
	static constexpr int ARRAY_SIZE = 2;

public:
	/// <summary>
	/// Creates matrixes and provides a set of mathematical operations user can perform on them
	/// Returns matrix
	/// </summary>
	/// <param name="matrix"> A 2x2 matrix </param>
	/// <param name="ARRAY_SIZE"> Value determining the amount of blocks in one row and column of the matrix </param>

	// Constructs a basic matrix fully filled with 0's.
	Macierz();

	// Copies values of a particular matrix while initializing.
	Macierz(const Macierz& rhs);

	// Destructs the previously created matrix.
	~Macierz();

	// Operator overload which allows user to multiple every value in a matrix by a set value.
	Macierz operator*(const double x);

	// Operator overload which allows user to copy all values from one matrix to another.
	Macierz& operator=(const Macierz& rhs);

	// Operator overload which allows user to combine all values from two matrixes and put the results into third matrix.
	Macierz operator+(const Macierz& rhs);

	// Operator overload that checks if two said matrixes contain identical values. If that's the case - returns true
	// in other case returns false.
	bool operator==(const Macierz& rhs);

	// Operator overload which increases all values in a matrix by a set value.
	Macierz operator+=(const double x);

	// Operator overload which decreases all values in a matrix by a set value.
	Macierz operator-=(const double x);

	// Operator overload which allows user to combine all values from two matrixes. Doesn't require a third matrix.
	Macierz& operator+=(const Macierz& rhs);

	// Operator overload which allows user to subtract all values from two matrixes and put the results into third matrix.
	Macierz operator-(const Macierz& rhs);

	// Operator overload which allows user to subtract all values from two matrixes. Doesn't require a third matrix.
	Macierz& operator-=(const Macierz& rhs);

	//Operator overload which allows user to multiply two matrixes by themselfes.
	Macierz& operator*=(const Macierz& rhs);

	// Operator overload which multiplies all values in a matrix by a set value.
	Macierz& operator*=(const double x);

	// Operator overload which prints out all contents of a said matrix
	friend std::ostream& operator<<(std::ostream& out, const Macierz& rhs);

	// Method that allows user to set x value on respectively i and j coordinates in a matrix
	void set(int i, int j, double x);

	// Method that allows user to print out a particular value on respectively i and j coordinates in a matrix
	double get(int i, int j);

	// Method that transpositions the matrix
	void transpozycja();

};

#endif	//_MACIERZ_H_