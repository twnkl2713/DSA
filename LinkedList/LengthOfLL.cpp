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

int LengthOfLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Linked List Elements: ";
    int length = LengthOfLinkedList(head);
    cout << "Length of Linked List: " << length << endl;
    return 0;

}