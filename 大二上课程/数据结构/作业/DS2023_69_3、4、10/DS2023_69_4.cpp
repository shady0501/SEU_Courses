#include <iostream>

using namespace std;

void Da(int* x, int n)
{
	int i = 1;
	int count = 1;

	do
	{
		x[i] += 2;
		i += 2;
		count += 2;

		count++;
	} while (i <= n);

	i = 1; 
	count++;

	while (i <= (n/2))
	{
		x[i] += x[i + 1];
		i++;
		count += 2;

		count++;
	}
	count++;
}

void Db(int* x, int n)
{
	int i = 1;
	int count = 1;

	for (int i = 1; i <= n;)
	{
		x[i] += 2;
		i += 2;
		count += 3;
	}
	i = 1;

	while (i <= (n / 2))
	{
		x[i] += x[i + 1];
		i++;
		count += 3;
	}
	count += 2;
}

//(c)   count = 3n+3;

/*(d)
                                 s/e             frequency           total steps
void D(int* x, int n)             0                   1                    0     
{                                 0                   1                    0     
	int i = 1;                    1                   1                    1  
	do                            0                   1                    0     
	{                             0                   n/2                  0     
		x[i] += 2;                1                   n/2                 n/2     
		i += 2;                   1                   n/2                 n/2  
	} while (i <= n);             1                   n/2                 n/2  
	i = 1;                        1                   1                    1 
	while (i <= (n/2))            1                 n/2 + 1             n/2 + 1 
	{                             0                   n/2                 n/2
		x[i] += x[i + 1];         0                   n/2                 n/2
		i++;                      0                   n/2                 n/2
	}                             0                   n/2                 n/2
}                                 0                   1                    0  
*/