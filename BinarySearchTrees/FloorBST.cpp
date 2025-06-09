#include <iostream>
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

int findFloor(Node* root, int key) {
    int floor = -1;
    while (root) {
        if (root->data == key) {
            return key; // exact match is the floor
        }
        if (root->data > key) {
            root = root->left; // move left to find smaller values
        } else {
            floor = root->data;  // possible floor
            root = root->right;  // try to find a larger valid floor
        }
    }
    return floor;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    int key = 10;
    int result = findFloor(root, key);
    if (result == -1)
        cout << "No floor found for " << key << endl;
    else
        cout << "Floor of " << key << " is " << result << endl;
    return 0;
}
