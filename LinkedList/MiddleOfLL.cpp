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

Node* findMiddleNode(Node* head) {
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // slow will be at middle
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Linked List: ";
    printList(head);
    Node* middle = findMiddleNode(head);
    if(middle != nullptr) {
        cout << "Middle node value: " << middle->data << endl;
    } else {
        cout << "The list is empty.\n";
    }
    return 0;
}