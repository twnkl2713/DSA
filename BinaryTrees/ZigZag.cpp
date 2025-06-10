#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currLevel;

        for (int i = 0; i < levelSize; i++) {
            Node* currNode = q.front();
            q.pop();
            currLevel.push_back(currNode->data);

            if (currNode->left != NULL) {
                q.push(currNode->left);
            }
            if (currNode->right != NULL) {
                q.push(currNode->right);
            }
        }

        if (!leftToRight) {
            reverse(currLevel.begin(), currLevel.end());
        }

        ans.push_back(currLevel);
        leftToRight = !leftToRight;
    }

    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
