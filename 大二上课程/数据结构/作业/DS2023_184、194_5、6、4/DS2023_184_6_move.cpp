
void rightMove(ChainNode* l,ChainNode* r, int n)
{
	ChainNode* temp;

	for (int i = 0; r->next != 0 && i < n; ++i)
	{
		temp = r;
		r = r->next;
		temp->next = l;
		l = temp;
	}

	if (r->next == 0)
	{
		l = r;
		r = 0;
	}
}

void leftMove(ChainNode* l, ChainNode* r, int n)
{
	ChainNode* temp;

	for (int i = 0; l->next != 0 && i < n; ++i)
	{
		temp = l;
		l = l->next;
		temp->next = r;
		r = temp;
	}

	if (l->next == 0)
	{
		r = l;
		l = 0;
	}
}