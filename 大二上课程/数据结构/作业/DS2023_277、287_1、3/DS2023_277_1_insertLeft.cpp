
template <class T>
void ThreadedTree<T>::InsertLeft(ThreadedNode<T>* s, 
	ThreadedNode<T>* l)
{
	l->leftChild = s->leftChild;
	l->leftThread = s->leftThread;
	l->rightChild = s;
	l->rightThread = true;
	s->leftChild = l;
	s->leftThread = false;
	if (!l->leftThread)
	{
		ThreadedNode<T>* temp = InorderPre(l);//中序前继节点
		temp->rightChild = l;
	}
}