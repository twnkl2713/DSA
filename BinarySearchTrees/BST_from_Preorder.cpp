#include<iostream>
#include<vector>
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

Node* buildBST(vector<int> &preorder, int &index, int min, int max) {
    if(index >= preorder.size()) {
        return NULL;
    }
    
    int currNode = preorder[index];
    if(currNode < min || currNode > max) {
        return NULL;
    }

    Node* root = new Node(currNode);
    index++;

    // all nodes in left st must be < root->data
    root->left = buildBST(preorder, index, min, currNode-1);
    // all nodes in right st must be > root->data
    root->right = buildBST(preorder, index, currNode+1, max);

    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return buildBST(preorder, index, INT_MIN, INT_MAX);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node* root = bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}




