
void deleteNode(ChainNode* x)
{
	if (x == fist)
	{
		first = x->link;
		delete x;
		return;
	}

	ChainNode* node = first;

	while (node->link != x)
	{
		node = node->link;
	}

	node->link = x->link;
	delete x;
}
//时间复杂度为O(n)