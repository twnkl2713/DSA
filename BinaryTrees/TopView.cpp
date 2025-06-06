#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void topView(Node* root) {
    vector<int> ans;
    if(root == NULL) {
        return;
    }
    queue<pair<Node*, int>> q; // (node, HD)
    map<int, int> mp; // <HD, node>
    q.push({root, 0});
    while(!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(mp.find(currHD) == mp.end()) { // not found
            mp[currHD] = curr->data;
        }
        if(curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }
    for(auto it: mp) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout << "Top view of the tree: ";
    topView(root);
    return 0;
}
