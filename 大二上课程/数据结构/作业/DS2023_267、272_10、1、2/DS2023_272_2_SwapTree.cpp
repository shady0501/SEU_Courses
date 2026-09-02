
void SwapTree(TreeNode* root)
{
	if (root)
	{
		TreeNode* temp;

		temp = root->rightChild;
		root->rightChild = root->leftChild;
		root->leftChild = temp;

		SwapTree(root->leftChild);
		SwapTree(root->rightChild);
	}
}