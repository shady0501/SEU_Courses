#include <iostream>

using namespace std;

int problemA(int n)
{
	int x = 0;
	int count = 0;

	for (int i = 1; i <= n; ++i)
	{
		count++;
		for (int j = 1; j <= i; ++j)
		{
			count++;
			for (int k = 1; k <= j; ++k)
			{
				count += 2;
				x++;
			}
			count++;
		}
		count++;
	}
	count++;

	return count;
}

int problemB(int n)
{
	int i = 1;
	int x = 0;

	while (i <= n)
	{
		x++;
		i++;
	}

	return x;
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	cout << "AÌâ = " << problemA(n) << endl;
	cout << "BÌâ = " << problemB(n);
}