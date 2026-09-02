#include <iostream>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;

    BinaryTreeNode(T value) : data(value), leftChild(nullptr), rightChild(nullptr) 
    {
    }
};

template <typename T>
class BinaryTree {
public:
    BinaryTreeNode<T>* root;

    BinaryTree() : root(nullptr) 
    {
    }

    BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2)
    {
        root = item;
        root->leftChild = bt1;
        root->rightChild = bt2;
    }

    ~BinaryTree() 
    {
        if (node != nullptr) {
            ~BinaryTreeTree(node->left);
            ~BinaryTree(node->right);
            delete node;
        }
    }

    bool isEmpty()
    {
        return root;
    }

    BinaryTree<T> LeftSubtree()
    {
        return root->leftChild;
    }

    BinaryTree<T> RightSubtree()
    {
        return root->rightChild;
    }

    T RootData()
    {
        return root->data;
    }

    void inorderTraversal(TreeNode* node) const 
    {
        if (node) 
        {
            inorderRecursive(node->left);
            std::cout << node->key << " ";
            inorderRecursive(node->right);
        }
    }

    void preorderTraversal(TreeNode* node) const
    {
        if (node) 
        {
            std::cout << node->key << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) const
    {
        if (node) 
        {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            std::cout << node->key << " ";
        }
    }

    void levelorderTraversal(TreeNode* node) const
    {
        if (node == nullptr)
            return;

        std::queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* current = q.front();
            std::cout << current->key << " ";
            q.pop();

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
};
