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

Node* detectCycle(Node* head) {
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;  
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; 
    Node* loopStart = detectCycle(head);
    if(loopStart) {
        cout << "Loop detected at node with value: " << loopStart->data << endl;
    } else {
        cout << "No loop detected in the linked list.\n";
    }
    return 0;
}

