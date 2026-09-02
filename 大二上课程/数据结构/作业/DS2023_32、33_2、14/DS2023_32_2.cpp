#include <iostream>

using namespace std;

int combination(int n)
{
	if (n == 1)
		return 2;

	return 2 * combination(n - 1);
}

int main()
{
	int n;
	cout << "输入n: ";
	cin >> n;

	cout << "所有可能的排列方式有" << combination(n) << "种。";

	return 0;
}