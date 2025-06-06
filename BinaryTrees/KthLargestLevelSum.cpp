#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

long long kthLargestLevelSum(Node* root, int k) {
    vector<long long> ans;
    if(root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0) {
        long long levelSum = 0;
        int levelSize = q.size();
        // processing all the nodes at the current level
        for(int i=0; i<levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            levelSum += curr->data;
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
        ans.push_back(levelSum);
    }
    // sorting the level sum in descending order to get the kth largest sum
    sort(ans.begin(), ans.end(), greater<long long>());
    if(k > ans.size()) {
        return -1; // if k is more than levels
    }
    return ans[k - 1];
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    int k = 2;
    cout << k << "-th largest level sum: " << kthLargestLevelSum(root, k) << endl;
    return 0;
}
