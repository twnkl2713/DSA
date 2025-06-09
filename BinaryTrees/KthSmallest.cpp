#include<iostream>
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

int solve(Node* root, int &i, int k) {
    if (root == NULL) return -1;

    // Left
    int left = solve(root->left, i, k);
    if (left != -1) return left;

    // Root
    i++;
    if (i == k) return root->data;

    // Right
    return solve(root->right, i, k);
}

int kthSmallest(Node* root, int k) {
    int i = 0;
    return solve(root, i, k);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    int k = 3;
    cout << k << "rd smallest element: " << kthSmallest(root, k) << endl;

    return 0;
}
