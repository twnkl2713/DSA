#include <iostream>
#include <unordered_map>
#include <vector>
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

int preIndex = 0;

int search(vector<int> &inorder, int left, int right, int val) {
    for(int i=left; i<=right; i++) {
        if(inorder[i] == val) {
            return i;
        }
    }
    return -1;
}
Node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right) {
    if(left > right) {
        return NULL;
    }
    Node* root = new Node(preorder[preIdx]);
    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;
    root->left = buildTreeHelper(preorder, inorder, preIdx, left, inIdx-1);
    root->right = buildTreeHelper(preorder, inorder, preIdx, inIdx + 1, right);
    return root;
}

Node* buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preIdx = 0;
    return buildTreeHelper(preorder, inorder, preIdx, 0, inorder.size()-1);
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}