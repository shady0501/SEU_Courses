#include <iostream>
#include <ctime>

using namespace std;

int BinarySearch(int* a, const int x, const int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle])right = middle - 1;
		else if (x > a[middle])left = middle + 1;
		else
			return middle;
	}
	return -1;
}

int main()
{
	int a[100], n[10];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		n[i] = 10 * i + 10;
	}
	cout << "n   time" << endl;
	for (int i = 0; i < 10; i++)
	{
		long start, stop;
		start = clock();
		for (int j = 0; j < 300000; ++j)
			BinarySearch(a, 50, n[i]);
		stop = clock();
		double runTime = (double)(stop - start) / CLOCKS_PER_SEC * 1000 / 300000;
		cout << n[i] << "   " << runTime << " ms" << endl;
	}
	return 0;
}
