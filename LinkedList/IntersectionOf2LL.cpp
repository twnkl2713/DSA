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

Node* sortedIntersection(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* dummy = new Node(0);
    Node* tail = dummy;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data) {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
    }
    return dummy->next;
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
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(6);
    head1->next->next->next->next = new Node(8);
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);
    Node* intersect = sortedIntersection(head1, head2);
    cout << "Intersection: ";
    printList(intersect);
    return 0;
}