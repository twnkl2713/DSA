#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long startIdx = q.front().second;
        unsigned long long endIdx = q.back().second;
        maxWidth = max(maxWidth, (int)(endIdx - startIdx + 1));

        for (int i = 0; i < levelSize; ++i) {
            auto currNode = q.front();
            q.pop();
            if(currNode.first->left) {
                    q.push({currNode.first->left, currNode.second*2+1});
            }
            if(currNode.first->right) {
                q.push({currNode.first->right, currNode.second*2+2});
            }
        }
    }
    return maxWidth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    int result = widthOfBinaryTree(root);
    cout << "Maximum width of binary tree: " << result << endl;
    return 0;
}
