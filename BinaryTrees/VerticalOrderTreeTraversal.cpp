#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    // map<x-coordinate, map<y-coordinate, multiset<node values>>>
    map<int, map<int, multiset<int>>> nodes;

    // Queue to do level order traversal and track (node, x, y)
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}}); // root at (x=0, y=0)

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        // Insert node's value at coordinates (x, y)
        nodes[x][y].insert(node->val);

        // Traverse left child: x-1, y+1
        if (node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }

        // Traverse right child: x+1, y+1
        if (node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

TreeNode* buildSampleTree() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();

    vector<vector<int>> result = verticalTraversal(root);

    cout << "Vertical Traversal Output:\n";
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
