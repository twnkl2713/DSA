#include<iostream>
#include<algorithm>
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

int minDepth(Node* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    if(root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    int minHeight = min(left, right) + 1;
    return minHeight;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Minimum depth of the binary tree is: " << minDepth(root) << endl;

    return 0;
}