
int calculate()
{
	Chain<int> y;
	Chain<int>::ChainIterator y1 = y.begin();
	Chain<int>::ChainIterator y2 = y.begin();
	y2 += 5;

	int sum = 0;

	while (y2 == y.end())
	{
		sum += (*y1)* (*y2);
	}

	return sum;
}