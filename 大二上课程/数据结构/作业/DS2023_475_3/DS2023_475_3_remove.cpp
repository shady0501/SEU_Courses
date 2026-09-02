
template <class K, class E>
void remove(const K& k)
{
	int i = h(k);
	int j = i;

	for (; ht[j]->first != k;)
	{
		j = (j + 1) % b;
		if (j == i)
		{
			cout << "cannot find k" << endl;
			return;
		}
	}

    pair<K, E> deleted = { K(), E() };

	if (ht[j] == deleted)
	{
		cout << "cannot find k" << endl;
		return;
	}

    ht[j] = deleted;
}

//如果删除了链中的一个元素并简单地将它设为空，
//那么在查找由于冲突而被插入到更远的位置的元素时可能会在这个空槽位停止，
//错误地认为元素不存在，从而出错。

//get函数修改：
 //   while (ht[j] != deleted && ht[j] != K() && ht[j].first != k) 
//	  { 
 //       j = (j + 1) % b;
 //       if (j == i) return nullptr; 
 //   }
 //   if (ht[j] == deleted || ht[j].first != k) return nullptr;

//新关键字可以插入到空槽中或者已删除的槽中