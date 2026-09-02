#include <iostream>

using namespace std;

int compare(int* a, int* b, int aTerm, int bTerm)
{
	for (int i = 0; i < aTerm && i < bTerm; ++i)
	{
		if (a[i] < b[i])
			return -1;
		else if (a[i] > b[i])
			return 1;
	}

	if (aTerm > bTerm)
		return 1;
	else if (aTerm < bTerm)
		return -1;

	return 0;
}