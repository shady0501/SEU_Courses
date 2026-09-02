#include <iostream>
#include <cmath>

using namespace std;

class Polynomial;

class Term
{
	friend Polynomial;

private:
	float coef;
	int exp;
};

class Polynomial
{
	int calculate(int);
private:
	Term* termArray;
	int capacity;
	int terms;
};

int Polynomial::calculate(int x0)
{
	int sum = 0;

	for (int i = 0; i < terms; ++i)
	{
		sum += termArray[i].coef * pow(x0, termArray[i].exp);
	}

	return sum;
}