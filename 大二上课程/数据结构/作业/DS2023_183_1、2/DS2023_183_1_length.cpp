

int length(ChainNode* firstNode)
{
	int counter = 0;

	ChainNode* next = firstNode;

	while (next != 0)
	{
		counter++;
		next = next->link;
	}

	return counter;
}
//时间复杂度为O(n)