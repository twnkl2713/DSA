#include<iostream>
#include<vector>
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

vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* IP = curr->left;
            while (IP->right != nullptr && IP->right != curr) {
                IP = IP->right;
            }
            if (IP->right == nullptr) {
                IP->right = curr; // Create thread
                curr = curr->left;
            } else {
                IP->right = nullptr; // Remove thread
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
