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

Node* moveToFront(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* secLast = NULL;
    Node* last = head;
    while(last->next != NULL) { // traverse to the last node
        secLast = last; // make the second last node as the last node and point it to NULL
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head; // now last node has come to the front and pointing to the head
    head = last;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original Linked List: ";
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    head = moveToFront(head);
    cout << "After moving last to front: ";
    temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    return 0;
}