
void DeleteNode(TreeNode* root,K* key)
{
	if (root)
	{
		TreeNode* node = root;
		TreeNode* pp = 0;
		int left = 0;

		while (node != nullptr && node->data.key != key)
		{
			if (node->data.key > key)
			{
				pp = node;
				node = node->leftChild;
				left = 1;
			}
			else
			{
				pp = node;
				node = node->rightChild;
				left = 0;
			}
		}

		if (node == nullptr)
			return;

		if (node->leftChild == nullptr && node->rightChild == nullptr)
		{
			if (left)
				pp->leftChild = nullptr;
			else
				pp->rightChild = nullptr;
		}
		else if (node->leftChild == nullptr && node->rightChild != nullptr)
		{
			if (left)
				pp->leftChild = node->rightChild;
			else
				pp->rightChild = node->rightChild;
		}
		else if (node->leftChild != nullptr && node->rightChild == nullptr)
		{
			if (left)
				pp->leftChild = node->leftChild;
			else
				pp->rightChild = node->leftChild;
		}
		else
		{
			int number = 0;
			TreeNode* nod = node->rightChild;
			TreeNode* nodpp = 0;

			while (nod->leftChild)
			{
				nodpp = nod;
				nod = nod->leftChild;
			}

			node->data.key = nod->data.key;

			if (nod->leftChild == nullptr && nod->rightChild == nullptr)
			{
					nodpp->leftChild = nullptr;
			}
			else if (nod->leftChild == nullptr && nod->rightChild != nullptr)
			{
					nodpp->leftChild = node->rightChild;
			}
		}
	}
}
//时间复杂度为O(h)