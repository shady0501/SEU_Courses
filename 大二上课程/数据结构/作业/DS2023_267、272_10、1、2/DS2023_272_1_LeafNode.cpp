
int countLeafNode(TreeNode* root)
{
	if (root)
	{
		if (root->leftChild == 0 && root->rightChild == 0)
			return 1;

		int leftNumber = coutLeadNode(root->leftChild);
		int rightNumber = coutLeadNode(root->rightChild);

		return leftNumber + rightNumber;
	}

	return 0;
}