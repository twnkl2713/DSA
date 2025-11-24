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

int countNodesInLoop(Node* head) {
    if(head == NULL) return 0;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            int count = 1;
            Node* temp = head;
            while(temp->next != slow) {
                temp = temp->next;
                count++;
            }
            return count;
        }
    }
    return 0; 
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; 
    int loopLength = countNodesInLoop(head);
    if(loopLength > 0) {
        cout << "Length of loop is: " << loopLength << endl;
    } else {
        cout << "No loop detected in the linked list.\n";
    }
    return 0;
}