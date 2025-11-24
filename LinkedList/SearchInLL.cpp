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

Node* searchInLinkedList(Node* head, int key) {
    Node* ptr = head;
    while(ptr != nullptr) {
        if(ptr->data == key) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Linked List: ";
    printLinkedList(head);
    int key = 3;
    Node* result = searchInLinkedList(head, key);
    if(result) {
        cout << "Element " << key << " found in the linked list." << endl;
    } else {
        cout << "Element " << key << " not found in the linked list." << endl;
    }
    return 0;
}