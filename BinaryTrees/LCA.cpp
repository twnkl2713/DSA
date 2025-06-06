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

Node* LCA(Node* root, Node* p, Node* q) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == p->data || root->data == q->data) {
        return root; // LCA
    }
    Node* leftLCA = LCA(root->left, p, q);
    Node* rightLCA = LCA(root->right, p, q);
    if(leftLCA && rightLCA) {
        return root;
    }
    else if(leftLCA != NULL) {
        return leftLCA;
    }
    else {
        return rightLCA;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Node* p = root->left->left;  // Node 4
    Node* q = root->left->right; // Node 5

    Node* lca = LCA(root, p, q);
    if (lca) {
        cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}