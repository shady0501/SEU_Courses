#include <iostream>

using namespace std;

class SparseMatrix;

class MatrixTerm
{
	friend class SparseMatrix;

private:
	int row, col, value;
};

class SparseMatrix
{
public:
	SparseMatrix(int a, int b, int c)
	{
		cols = a;
		rows = b;
		terms = c;
	}

	SparseMatrix FastTranspose();

private:
	int rows, cols, terms, capacity;
	MatrixTerm* smArray;
};

SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols, rows, terms);

	if (terms > 0)
	{
		//int* rowSize = new int[cols];
		//int* rowStart = new int[cols];
		int* rowS = new int[cols];

		//fill(rowSize, rowSize + cols, 0);
		fill (rowS, rowS + cols, 0);

		for (int i = 0; i < terms; ++i)
		{
			//rowSize[smArray[i].col]++;
			rowS[smArray[i].col]++;
		}

		//rowStart[0] = 0;

		int number1 = 0;
		int number2 = 0;

		for (int i = 1; i < cols; ++i)
		{
			//rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
			number1 = rowS[i];
			rowS[i] = rowS[i - 1] + number2;
			number2 = number1;
		}

		for (int i = 0; i < terms; i++)
		{
			//int j = rowStart[smArray[i].col];
			int j = rowS[smArray[i].col];

			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;

			rowS[smArray[i].col]++;
			//rowStart[smArray[i].col]++;
		}

		delete[] rowS;
		//delete[] rowSize;
		//delete[] rowStart;
	}
	return b;
}