#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void allPaths(TreeNode* root, string path, vector<string> &ans) {
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }
    if(root->left) {
        allPaths(root->left, path + "->" + to_string(root->left->val), ans);
    }
    if(root->right) {
        allPaths(root->right, path + "->" + to_string(root->right->val), ans);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root == NULL) return ans; // safety check
    string path = to_string(root->val);
    allPaths(root, path, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    vector<string> result = binaryTreePaths(root);
    cout << "All root-to-leaf paths:" << endl;
    for(const string& path : result) {
        cout << path << endl;
    }

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
