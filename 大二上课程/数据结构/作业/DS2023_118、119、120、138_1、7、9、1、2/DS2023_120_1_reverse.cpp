
int* reverse(int* list, int item)
{
		int number = 0;

	for (int i = 0; i < item / 2; ++i)
	{
		number = list[i];
		list[i] = list[item - i - 1];
		list[item - i - 1] = number;
	}

	return list;
}

//¼ÆËãÊ±¼ä£ºO(n)