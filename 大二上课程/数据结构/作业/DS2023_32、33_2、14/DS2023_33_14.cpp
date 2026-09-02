#include <iostream>

using namespace std;

int recursive(int n)
{
	if (n == 0)
		return 1;

	return 2 * recursive(n - 1);
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	cout << "含有" << n << "个元素的幂集种包含的所有子集共有" << recursive(n) << "种。";

	return 0;
}