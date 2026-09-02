#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node 
{
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) 
    {
    }
};

void insert(Node*& root, int data) 
{
    if (root == nullptr)
        root = new Node(data);
    else if (data < root->data) 
        insert(root->leftChild, data);
    else 
        insert(root->rightChild, data);
}

int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = getHeight(root->leftChild);
        int rightHeight = getHeight(root->rightChild);
        return 1 + max(leftHeight, rightHeight);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int n_values[] = { 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };

    for (int n : n_values) 
    {
        Node* root = 0;

        for (int i = 0; i < n; ++i) 
        {
            int value = std::rand();
            insert(root, value);
        }

        int height = getHeight(root);

        double ratio = static_cast<double>(height) / log2(n);

        cout << "n = " << n << ", Height = " << height << ", Height/Log2(n) = " << ratio << endl;
    }

    return 0;
}
