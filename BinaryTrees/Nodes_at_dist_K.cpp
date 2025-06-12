#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Step 1: Create a map of each node to its parent using BFS
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* current = q.front(); q.pop();
        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

// Step 2: BFS from target node to find all nodes at distance k
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track; // child -> parent
    markParents(root, parent_track);  // Fill the parent mapping

    unordered_set<TreeNode*> visited; // Track visited nodes to prevent cycles
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);
    int curr_level = 0;

    // BFS until we reach the k-th level
    while(!q.empty()) {
        int size = q.size();
        if(curr_level++ == k) break;

        for(int i = 0; i < size; ++i) {
            TreeNode* current = q.front(); q.pop();

            // Visit left child
            if(current->left && !visited.count(current->left)) {
                q.push(current->left);
                visited.insert(current->left);
            }

            // Visit right child
            if(current->right && !visited.count(current->right)) {
                q.push(current->right);
                visited.insert(current->right);
            }

            // Visit parent
            if(parent_track.count(current) && !visited.count(parent_track[current])) {
                q.push(parent_track[current]);
                visited.insert(parent_track[current]);
            }
        }
    }

    // Step 3: Collect all nodes at distance k
    vector<int> result;
    while(!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Target node is 5, find all nodes at distance 2
    TreeNode* target = root->left; // Node with value 5
    int k = 2;

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
