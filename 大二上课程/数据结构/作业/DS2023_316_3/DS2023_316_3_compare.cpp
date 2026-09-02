#include <iostream>
#include <ctime>

using namespace std;

class Sets 
{
public:
	Sets(int);
	~Sets();
	void SimpleUnion(int, int);
	int SimpleFind(int);
	void WeightedUnion(int, int);
	int CollapsingFind(int);
	int treeHeight();
private:
	int* parent;
	int n;
};

Sets::Sets(int numberOfElements)
{
	if (numberOfElements < 2)
		throw "Must have at least 2 elements.";
	n = numberOfElements;
	parent = new int[n];
	fill(parent, parent + n, -1);
}

Sets::~Sets() {
	delete[] parent;
}

void Sets::SimpleUnion(int i, int j)
{
	parent[i] = j;
}

int Sets::SimpleFind(int i)
{
	while (parent[i] >= 0)
		i = parent[i];
	return i;
}

void Sets::WeightedUnion(int i, int j)
{
	int temp = parent[i] + parent[j];

	if (parent[i] > parent[j])
	{
		parent[i] = j;
		parent[j] = temp;
	}
	else
	{
		parent[j] = i;
		parent[i] = temp;
	}
}

int Sets::CollapsingFind(int i)
{
	int r = i;
	//cout << "SLKJFDF" << endl;
	for (; parent[r] >= 0; r = parent[r]);
	//cout << "@#@$" << endl;
	while (i != r)
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}

	return r;
}

int Sets::treeHeight()
{
	int max = 0;

	for (int i = 0; i < n; ++i)
	{
		int a = i;
		int counter = 1;

		while (parent[a] >= 0)
		{
			a = parent[a];
			counter++;
		}

		if (counter > max)
			max = counter;
	}

	return max;
}

int main() 
{
	cout << "测试 SimpleUnion:\n";
	long start1, stop1, time1, start2, stop2, time2;
	start1 = clock();
	int ti = 10000000;
	Sets simpleSets(8);
	simpleSets.SimpleUnion(0, 1);
	simpleSets.SimpleUnion(1, 2);
	simpleSets.SimpleUnion(2, 3);
	simpleSets.SimpleUnion(3, 4);
	simpleSets.SimpleUnion(4, 5);
	simpleSets.SimpleUnion(5, 6);
	simpleSets.SimpleUnion(6, 7);
	for (int i = 0; i < ti; ++i)
	{
		Sets simpleSets(8);
		simpleSets.SimpleUnion(0, 1);
		simpleSets.SimpleUnion(1, 2);
		simpleSets.SimpleUnion(2, 3);
		simpleSets.SimpleUnion(3, 4);
		simpleSets.SimpleUnion(4, 5);
		simpleSets.SimpleUnion(5, 6);
		simpleSets.SimpleUnion(6, 7);
	}
	stop1 = clock();
	time1 = stop1 - start1;
	cout << "SimpleUnion树高为：" << simpleSets.treeHeight() << endl;
	cout << "SimpleUnion所需时间为：" << time1/ti << " ms" << endl;

	// 测试 WeightedUnion
	cout << "\n测试 WeightedUnion:\n";
	start2 = clock();
	Sets weightedSets(8);
	weightedSets.WeightedUnion(0, 1);
	weightedSets.WeightedUnion(1, 2);
	weightedSets.WeightedUnion(2, 3);
	weightedSets.WeightedUnion(3, 4);
	weightedSets.WeightedUnion(4, 5);
	weightedSets.WeightedUnion(5, 6);
	weightedSets.WeightedUnion(6, 7);
	for (int i = 0; i < ti; ++i)
	{
		Sets weightedSets(8);
		weightedSets.WeightedUnion(0, 1);
		weightedSets.WeightedUnion(1, 2);
		weightedSets.WeightedUnion(2, 3);
		weightedSets.WeightedUnion(3, 4);
		weightedSets.WeightedUnion(4, 5);
		weightedSets.WeightedUnion(5, 6);
		weightedSets.WeightedUnion(6, 7);
	}
	stop2 = clock();
	time2 = stop2 - start2;
	cout << "weightedUnion树高为：" << weightedSets.treeHeight() << endl;
	cout << "weightedUnion所需时间为：" << time2/ti << " ms" << endl;

	Sets findSets1(8);
	findSets1.WeightedUnion(0, 1);
	findSets1.WeightedUnion(2, 3);
	findSets1.WeightedUnion(4, 5);
	findSets1.WeightedUnion(6, 7);
	findSets1.WeightedUnion(0, 2);
	findSets1.WeightedUnion(4, 6);
	findSets1.WeightedUnion(0, 4);

	int times = 1000000;
	long collapsingStart1, collapsingStop1, collapsingStart2, collapsingStop2,
		 simpleStart1, simpleStop1, simpleStart2, simpleStop2;

	simpleStart1 = clock();
	for (int j = 0; j < times; ++j)
	{
		findSets1.SimpleFind(7);
	}
	simpleStop1 = clock();
	double simpleTime1 = (double)(simpleStop1 - simpleStart1) / CLOCKS_PER_SEC * 1000 / times;
	cout << "SimpleFind一次搜索7所需时间：" << simpleTime1 << " ms" << endl;

	simpleStart2 = clock();
	for (int j = 0; j < times; ++j)
	{
		findSets1.SimpleFind(7);
		findSets1.SimpleFind(7);
		findSets1.SimpleFind(7);
		findSets1.SimpleFind(7);
		findSets1.SimpleFind(7);
	}
	simpleStop2 = clock();
	double simpleTime2 = (double)(simpleStop2 - simpleStart2) / CLOCKS_PER_SEC * 1000 / times;
	cout << "SimpleFind五次搜索7所需时间：" << simpleTime2 << " ms" << endl;

	collapsingStart1 = clock();
	for (int j = 0; j < times; ++j)
	{
		findSets1.CollapsingFind(7);
	}
	collapsingStop1 = clock();
	double collapsingTime1 = (double)(collapsingStop1 - collapsingStart1) / CLOCKS_PER_SEC * 1000 / times;
	cout << "CollapsingFind一次搜索7所需时间：" << collapsingTime1 << " ms" << endl;

	Sets findSets2(8);

	collapsingStart2 = clock();
	for (int j = 0; j < times; ++j)
	{
		findSets2.CollapsingFind(7);
		findSets2.CollapsingFind(7);
		findSets2.CollapsingFind(7);
		findSets2.CollapsingFind(7);
		findSets2.CollapsingFind(7);
	}
	collapsingStop2 = clock();
	double collapsingTime2 = (double)(collapsingStop2 - collapsingStart2) / CLOCKS_PER_SEC * 1000 / times;
	cout << "CollapsingFind五次搜索7所需时间：" << collapsingTime2 << " ms" << endl;

	return 0;
}