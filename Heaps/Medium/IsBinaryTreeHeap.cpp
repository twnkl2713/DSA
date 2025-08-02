#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int cnt) {
    if (root == NULL) return true;
    if (index >= cnt) return false;

    bool left = isCBT(root->left, 2 * index + 1, cnt);
    bool right = isCBT(root->right, 2 * index + 2, cnt);

    return (left && right);
}

bool isMaxOrder(Node* root) {
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
        return (root->data >= root->left->data) && isMaxOrder(root->left);

    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (root->data >= root->left->data &&
                root->data >= root->right->data &&
                left && right);
    }
}

bool isHeap(Node* root) {
    int nodeCount = countNodes(root);
    return isCBT(root, 0, nodeCount) && isMaxOrder(root);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    if (isHeap(root))
        cout << "The tree is a Max Heap\n";
    else
        cout << "The tree is NOT a Max Heap\n";
    return 0;
}
