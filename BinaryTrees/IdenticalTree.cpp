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
    if(p == NULL && q == NULL) {
        return true;
    }
    if(p == NULL && q != NULL) {
        return false;
    }
    if(p != NULL && q == NULL) {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool value = p->data == q->data;
    if(left && right && value) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2 (Same as Tree 1)
    Node* root2 = new Node(1);
    root2->left = new Node(4);
    root2->right = new Node(3);

    if (isSameTree(root1, root2)) {
        cout << "Both trees are the same" << endl;
    } else {
        cout << "Trees are different" << endl;
    }

    return 0;
}
