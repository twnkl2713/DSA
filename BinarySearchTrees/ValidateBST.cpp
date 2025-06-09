#include<iostream>
#include<climits>
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

bool valid(Node* root, long long min, long long max) {
    if (root == nullptr) return true;
    if (root->data > min && root->data < max) {
        bool left = valid(root->left, min, root->data);
        bool right = valid(root->right, root->data, max);
        return left && right;
    }
    return false;
}

bool isValidBST(Node* root) {
    return valid(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isValidBST(root)) {
        cout << "The tree is a valid BST" << endl;
    } else {
        cout << "The tree is NOT a valid BST" << endl;
    }
    return 0;
}
