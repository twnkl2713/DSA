#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr != NULL || !st.empty()) {
        // push root and left subtree, but process Before going left
        while(curr != NULL) {
            preorder.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        // move to the right subtree
        curr = curr->right;
    }
    return preorder;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = preorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}