
void BuildLoserTree()
{
	for (int i = k - 1; i > 0; i--)
	{
		if (getKey(2 * i) > getKey(2 * i + 1))
			l[i] = getIndex(2 * i + 1);
		else 
			l[i] = getIndex(2 * i);
	}
		
	l[0] = l[1];

	for (int i = 1; i < k; i++)
	{
		if (l[i] == getIndex(2 * i))
			l[i] = getIndex(2 * i + 1);
		else 
			l[i] = getIndex(2 * i);
	}
}

int getKey(int i) 
{
	if (i < k) 
		return buf[l[i]].key; 
	else 
		return buf[i - k].key;
		
}
int getIndex(int i) 
{
	if (i < k)
		return l[i];
	else
		return (i - k);
}