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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* multiply(Node* head, int x) {
    head = reverse(head);
    Node* temp = head;
    Node* prev = NULL;
    int carry = 0;
    while(temp != NULL) {
        int prod = temp->data * x + carry;
        temp->data = prod % 10;
        carry = prod / 10;
        prev = temp;
        temp = temp->next;
    }
    while(carry > 0) {
        Node* newNode = new Node(carry % 10);
        prev->next = newNode;
        carry = carry / 10;
        prev = prev->next;
    }
    head = reverse(head);
    return head;
}

Node* factorial(int n) {
    Node* head = new Node(1);
    for(int i=2; i<=n; i++) {
        head = multiply(head, i);
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n = 100;
    Node* fact = factorial(n);
    cout << "Factorial of " << n << " is: ";
    printList(fact);
    return 0;
}