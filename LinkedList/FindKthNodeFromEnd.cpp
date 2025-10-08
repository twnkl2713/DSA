#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* findKthFromEnd(Node* head, int k) {
    if(head == NULL || k <= 0) return NULL;
    Node* slow = head;
    Node* fast = head;
    for(int i=0; i<k; i++) {
        if(fast == NULL) return NULL;
        fast = fast->next;
    }
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    int k = 2;
    Node* kthNode = findKthFromEnd(head, k);
    if (kthNode != nullptr) {
        cout << k << "th node from the end is: " << kthNode->data << endl;
    } else {
        cout << "Invalid k\n";
    }
    return 0;
}