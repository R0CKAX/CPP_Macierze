#include "macierz.h"
#include <iostream>

Macierz::Macierz()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
	std::cout << "Konstruktor Macierzy" << '\n';
}

Macierz::Macierz(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] = rhs.matrix[i][j];
		}
	}
	std::cout << "Konstruktor Macierzy" << '\n';
}

Macierz::~Macierz()
{
	std::cout << "Destruktor Macierzy" << '\n';
}

Macierz Macierz::operator*(const double x)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] *= x;
		}
	}
	return Macierz(*this);
}

Macierz& Macierz::operator=(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] = rhs.matrix[i][j];
		}
	}
	return *this;
}

Macierz Macierz::operator+(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] += rhs.matrix[i][j];
		}
	}
	return Macierz(*this);
}

bool Macierz::operator==(const Macierz& rhs)
{
	int checkSum = ARRAY_SIZE * ARRAY_SIZE;	// amount of blocks in a matrix
	int checker = 0;	// variable checking how many blocks in matrixes are the same value

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			if (this->matrix[i][j] == rhs.matrix[i][j])
			{
				checker++;
			}
			else
			{

			}
		}
	}

	if (checker == checkSum)
	{
		std::cout << "Porównywane macierze s¹ identyczne." << '\n';
		return true;
	}
	else
	{
		std::cout << "Porównywane macierze s¹ ró¿ne." << '\n';
		return false;
	}
}

Macierz Macierz::operator+=(const double x)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] += x;
		}
	}
	return Macierz(*this);
}

Macierz Macierz::operator-=(const double x)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] -= x;
		}
	}
	return Macierz(*this);
}

Macierz& Macierz::operator+=(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] += rhs.matrix[i][j];
		}
	}
	return *this;
}

Macierz Macierz::operator-(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] -= rhs.matrix[i][j];
		}
	}
	return Macierz(*this);
}

Macierz& Macierz::operator-=(const Macierz& rhs)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] -= rhs.matrix[i][j];
		}
	}
	return *this;
}

Macierz& Macierz::operator*=(const Macierz& rhs)
{
	double tmp[2][2] = { {0, 0},{0, 0} };	// temporary matrix

	tmp[0][0] = this->matrix[0][0] * rhs.matrix[0][0] + this->matrix[0][1] * rhs.matrix[1][0];
	tmp[0][1] = this->matrix[0][0] * rhs.matrix[0][1] + this->matrix[0][1] * rhs.matrix[1][1];
	tmp[1][0] = this->matrix[1][0] * rhs.matrix[0][0] + this->matrix[1][1] * rhs.matrix[1][0];
	tmp[1][1] = this->matrix[1][0] * rhs.matrix[0][1] + this->matrix[1][1] * rhs.matrix[1][1];

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] = tmp[i][j];
		}
	}
	return *this;
}

Macierz& Macierz::operator*=(const double x)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] *= x;
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Macierz& rhs)
{
	return out << rhs.matrix[0][0] << " " << rhs.matrix[0][1] << std::endl << rhs.matrix[1][0] << " " << rhs.matrix[1][1] << std::endl;
}

void Macierz::set(int i, int j, double x)
{
	this->matrix[i][j] = x;
}

double Macierz::get(int i, int j)
{
	std::cout << this->matrix[i][j] << '\n';
	return 0;
}

void Macierz::transpozycja()
{
	double tmp[2][2] = { {0, 0},{0, 0} };	// temporary matrix
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			tmp[i][j] = this->matrix[i][j];
		}
	}
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			this->matrix[i][j] = tmp[j][i];
		}
	}
}