#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Step 1: Inorder Traversal (BST gives sorted values)
void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Step 2: Preorder Traversal to convert to Min Heap
void bstToMinHeap(Node* root, vector<int>& inorder, int& index) {
    if (!root) return;
    root->data = inorder[index++];
    bstToMinHeap(root->left, inorder, index);
    bstToMinHeap(root->right, inorder, index);
}

void convertBSTToMinHeap(Node* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);     // Get sorted values
    int index = 0;
    bstToMinHeap(root, inorder, index);  // Fill in Min Heap fashion
}

// Preorder traversal for checking
void preorderPrint(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTToMinHeap(root);

    cout << "Preorder of Min Heap: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}
