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

Node* addOne(Node* head) {
    if(head == NULL) return new Node(1);
    head = reverseList(head);
    Node* curr = head;
    int carry = 1;
    while(curr != NULL) {
        curr->data = curr->data + carry;
        if(curr->data < 10) {
            carry = 0;
            break;
        }
        else {
            curr->data = 0;
            carry = 1;
        }
        curr = curr->next;
    }
    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    head = reverseList(head);
    return head;
}

/*
int addHelper(Node* temp) {
    if(temp == NULL) return 1;
    int carry = addHelper(temp->next);
    temp->data += carry;
    if(temp->data < 10) {
        return 0;
    } else {
        temp->data = 0;
        return 1;
    }
}

Node* addOne(Node* head) {
    int carry = addHelper(head);
    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
*/

int main() {
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    head = addOne(head);
    cout << "List after adding one: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}