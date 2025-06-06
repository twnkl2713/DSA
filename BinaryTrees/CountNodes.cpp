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

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    return leftNodes + rightNodes + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Total nodes of the tree: " << countNodes(root) << endl;

    return 0;
}
