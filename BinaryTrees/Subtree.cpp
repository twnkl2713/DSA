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

bool isSameTree(Node* p, Node* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool value = (p->data == q->data);
    return left && right && value;
}

bool isSubtree(Node* root, Node* subroot) {
    if(root == NULL || subroot == NULL) {
        return root == subroot;
    }
    if(root->data == subroot->data && isSameTree(root, subroot)) {
        return true;
    }
    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);

    if (isSubtree(root, subroot)) {
        cout << "Subtree exists in the main tree" << endl;
    } else {
        cout << "Subtree does NOT exist in the main tree" << endl;
    }

    return 0;
}