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

void printKthLevel(Node* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 1) { // find out where k = 1 and print it
        cout << root->data;
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int k = 3;
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);
    cout << endl;

    return 0;
}