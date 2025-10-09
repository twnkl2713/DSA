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

Node* sortTwoLists(Node* l1, Node* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    Node* head1 = l1;
    Node* head2 = l2;
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        else {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
    }
    if(head1 != NULL) {
        temp->next = head1;
    }
    else {
        temp->next = head2;
    }
    return dummyNode->next;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
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
    Node* mergedHead = sortTwoLists(head1, head2);
    cout << "Merged Sorted List: ";
    temp = mergedHead;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}
