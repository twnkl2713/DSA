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

Node* nextRight = NULL;

void flatten(Node* root) {
    if (root == NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

void printFlattened(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);

    cout << "Flattened tree (right-skewed list): ";
    printFlattened(root);

    return 0;
}
