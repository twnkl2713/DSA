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

Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if(first->data != second->data) {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    cout << "Linked List: ";
    printList(head);
    if(isPalindrome(head)) {
        cout << "The linked list is a palindrome.\n";
    } else {
        cout << "The linked list is not a palindrome.\n";
    }
    return 0;
}