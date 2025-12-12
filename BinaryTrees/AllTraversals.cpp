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

vector<vector<int>> preInPostTraversal(TreeNode* root) {
    vector<int> pre, in, post;
    if (root == NULL) return {pre, in, post};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {
            pre.push_back(it.first->val);
            it.second = 2;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        // Inorder
        else if (it.second == 2) {
            in.push_back(it.first->val);
            it.second = 3;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }

        // Postorder
        else {
            post.push_back(it.first->val);
        }
    }

    return {pre, in, post};
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> ans = preInPostTraversal(root);

    cout << "Preorder: ";
    for (int x : ans[0]) cout << x << " ";
    cout << endl;

    cout << "Inorder:  ";
    for (int x : ans[1]) cout << x << " ";
    cout << endl;

    cout << "Postorder:";
    for (int x : ans[2]) cout << x << " ";
    cout << endl;

    return 0;
}
