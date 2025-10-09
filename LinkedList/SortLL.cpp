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

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* L1, Node* L2) {
    if(L1 == NULL) return L2;
    if(L2 == NULL) return L1;
    Node* dummy = new Node(0);
    Node* tail = dummy;
    while(L1 != NULL && L2 != NULL) {
        if(L1->data < L2->data) {
            tail->next = L1;
            tail = tail->next;
            L1 = L1->next;
        }
        else {
            tail->next = L2;
            tail = tail->next;
            L2 = L2->next;
        }
    }
    if(L1 != NULL) {
        tail->next = L1;
    }
    if(L2 != NULL) {
        tail->next = L2;
    }
    return dummy->next;
}

Node* sortLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* mid = findMiddle(head);
    Node* rightHead = mid->next;
    mid->next = NULL;
    Node* left = sortLL(head);
    Node* right = sortLL(rightHead);
    return mergeTwoLists(left, right);
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);
    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    head = sortLL(head);
    cout << "Sorted List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}