
void mergeLink(ChainNode* x,ChainNode* y)
{
	ChainNode* z = new ChainNode();
	ChainNode* current = z;

	for (; x != 0 && y != 0;)
	{
		if (x->data <= y->data)
		{
			current = x;
			current = current->next;
			x = x->next;
		}
		else
		{
			current = y;
			current = current->next;
			y = y->next;
		}
	}

	while (x)
	{
		current = x;
		current = current->next;
		x = x->next;
	}

	while (y)
	{
		current = y;
		current = current->next;
		y = y->next;
	}
}
//若x、y两链表中最长的长度为n，则时间复杂度为O(n)