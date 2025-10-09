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

Node* findNthNode(Node* temp, int n) {
    int count = 1;
    while(temp != NULL){
        if(count == n) return temp;
        count++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head, int n) {
    if(head == NULL || head->next == NULL || n == 0) return head;
    int len = 1;
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
        len++;
    }
    if(n % len == 0) return head;
    n = n % len;
    tail->next = head; // Connect tail to head to make it circular
    Node* newLastNode = findNthNode(head, len - n);
    head = newLastNode->next; // New head is next of new last node
    newLastNode->next = NULL; // Break the circular link
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int n = 2; // Number of positions to rotate
    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    head = rotateLL(head, n);
    cout << "Rotated List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}