#include <iostream>
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

Node* helper(vector<int>& nums, int st, int end) {
    if (st > end) return NULL;
    int mid = st + (end - st) / 2;
    Node* root = new Node(nums[mid]);
    root->left = helper(nums, st, mid - 1);
    root->right = helper(nums, mid + 1, end);
    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

// Inorder Traversal to check if BST is correctly built
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> sortedArr = {-10, -3, 0, 5, 9};
    
    Node* bstRoot = sortedArrayToBST(sortedArr);

    cout << "Inorder Traversal of BST: ";
    inorder(bstRoot);
    cout << endl;

    return 0;
}
