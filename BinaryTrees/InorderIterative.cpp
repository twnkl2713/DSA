#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr != NULL || !st.empty()) {
        // push all the left children
        while(curr != NULL) {
            st.push(curr); // push the root first
            curr = curr->left; // start moving to the left
        }
        curr = st.top();
        st.pop();
        inorder.push_back(curr->val);
        // move to the right subtree
        curr = curr->right;
    }
    return inorder;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = inorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}