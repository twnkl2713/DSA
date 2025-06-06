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

int maxDiam = 0;

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    maxDiam = max(maxDiam, leftHeight+rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root) {
    maxDiam = 0;
    height(root);
    return maxDiam;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Diameter of the binary tree: " << diameter(root) << endl;
    return 0;
}
