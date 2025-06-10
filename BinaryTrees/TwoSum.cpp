#include<iostream>
#include<unordered_set>
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

bool find(Node* root, int k, unordered_set<int> &seen) {
    if (root == NULL) {
        return false;
    }
    if (seen.count(k - root->data)) {
        return true;
    }
    seen.insert(root->data);
    return find(root->left, k, seen) || find(root->right, k, seen);
}

bool findTarget(Node* root, int k) {
    unordered_set<int> seen;
    return find(root, k, seen);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    int k = 9;

    if (findTarget(root, k)) {
        cout << "Pair found\n";
    } else {
        cout << "No pair found\n";
    }
    return 0;
}
