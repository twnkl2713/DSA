#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL) {
            st1.push(root->left);
        }
        if(root->right != NULL) {
            st1.push(root->right);
        }
    }
    while(!st2.empty()) {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}