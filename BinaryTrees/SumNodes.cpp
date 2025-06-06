#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftNodes = sum(root->left);
    int rightNodes = sum(root->right);
    return leftNodes + rightNodes + root->data;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Sum of the nodes of the tree: " << sum(root) << endl;

    return 0;
}
