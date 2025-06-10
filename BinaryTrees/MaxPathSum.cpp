#include<iostream>
#include<vector>
#include<climits>
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

int max_sum;

int maxGain(Node* node) {
    if (node == NULL) return 0;

    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    int currPathSum = node->data + leftGain + rightGain;

    max_sum = max(max_sum, currPathSum);

    return node->data + max(leftGain, rightGain);
}

int maxPathSum(Node* root) {
    max_sum = INT_MIN;
    maxGain(root);
    return max_sum;
}

int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
