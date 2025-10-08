#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* arrayToLinkedList(int arr[], int n) {
    if(n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i=1; i<n; i++) {
        ptr->next = new Node(arr[i]);
        ptr = ptr->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLinkedList(arr, n);
    printLinkedList(head);
    return 0;
}