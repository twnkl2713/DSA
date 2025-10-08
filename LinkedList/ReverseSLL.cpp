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

Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original Linked List:\n";
    printList(head);
    head = reverseLL(head);
    cout << "Reversed Linked List:\n";
    printList(head);
    return 0;
}