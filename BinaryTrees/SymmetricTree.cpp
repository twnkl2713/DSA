#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isMirror(Node* left, Node* right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(Node* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric" << endl;
    } else {
        cout << "The tree is not symmetric" << endl;
    }
    return 0;
}
