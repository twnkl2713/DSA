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

int findCeil(Node* root, int key) {
    int ceil = -1;
    while (root) {
        if (root->data == key) {
            return key;
        }
        if (root->data < key) {
            root = root->right; // move right to find larger values
        } else {
            ceil = root->data;  // possible ceil
            root = root->left;  // try to find smaller valid ceil
        }
    }
    return ceil;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    int key = 10;
    int result = findCeil(root, key);

    if (result == -1)
        cout << "No ceil found for " << key << endl;
    else
        cout << "Ceil of " << key << " is " << result << endl;

    return 0;
}
