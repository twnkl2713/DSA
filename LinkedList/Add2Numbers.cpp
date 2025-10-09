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

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add2Lists(Node* l1,Node* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    int carry = 0;
    while(l1 != NULL && l2 != NULL) {
        int sum = carry;
        if(l1 != NULL) {
            sum += l1->data;
        }
        if(l2 != NULL) {
            sum += l2->data;
        }
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        temp->next = newNode;
        temp = temp->next;
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    if(carry > 0) {
        Node* newNode = new Node(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    return reverseList(dummyNode->next);
}

int main() {
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);
    cout << "List 1: ";
    Node* temp = head1;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "List 2: ";
    temp = head2;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    Node* result = add2Lists(head1, head2);
    cout << "Resultant List: ";
    temp = result;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}