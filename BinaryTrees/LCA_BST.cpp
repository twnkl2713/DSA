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

Node* LCA_BST(Node* root, Node* p, Node* q) {
    if(root == NULL) return NULL;
    // if both p and q are less than root, LCA lies in left side
    if(p->data < root->data && q->data < root->data) {
        return LCA_BST(root->left, p, q);
    }
    // if both p and q are greater than root, LCA lies in right side
    else if(p->data > root->data && q->data > root->data) {
        return LCA_BST(root->right, p, q);
    }
    // if p and q lie on diff sides(or one equals the root), root is the LCA
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Node* p = root->left->left;  // Node 5
    Node* q = root->left->right; // Node 15

    Node* lca = LCA_BST(root, p, q);
    if (lca) {
        cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    return 0;
}
