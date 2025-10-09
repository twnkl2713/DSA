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

Node* removeDuplicates(Node* head) {
    Node* temp = head;
    while(temp != NULL && temp->next != NULL) {
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) {
            nextNode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(1);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    head = removeDuplicates(head);
    cout << "List after removing duplicates: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}