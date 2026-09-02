#include <iostream>
#include <string>
#include <vector>

using namespace std;

class String
{
public:
	vector<int> Frequency(string t);
};

vector<int> String::Frequency(string t)
{
	vector<int> frequency(256, 0);
	int length = t.length();

	for (int i = 0; i < length; ++i)
	{
		frequency[static_cast<int>(t[i])]++;
	}

	return frequency;
}

int main()
{
	string str;
	String s;

	cout << "ÊäÈë×Ö·û´®£º";
	cin >> str;

	vector<int> frequency = s.Frequency(str);

	for (int i = 0; i < 256; ++i)
	{
		if (frequency[i] != 0)
		{
			char c = static_cast<char>(i);
			cout << c << "      " << frequency[i] << endl;
		}
	}

	return 0;
}
