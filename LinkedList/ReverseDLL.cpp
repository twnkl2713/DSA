#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }  
};

Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* curr = head;
    Node* prevNode = NULL;
    while(curr != NULL) {
        prevNode = curr->prev;
        curr->prev = curr->next;
        curr->next = prevNode;
        curr = curr->prev;
    }
    if(prevNode != NULL) {
        head = prevNode->prev;
    }
    return head;
}

Node* deleteDLLRecursively(Node* head) {
    if (head == nullptr) return nullptr;
    deleteDLLRecursively(head->next);
    delete head;
    return nullptr;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    cout << "Original DLL:\n";
    printDLL(head);
    head = reverseDLL(head);
    cout << "Reversed DLL:\n";
    printDLL(head);
    return 0;
}