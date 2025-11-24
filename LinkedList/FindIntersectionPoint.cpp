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

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }       
    return count;
}

Node* getIntersection(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if(len1 > len2) {
        for(int i=0; i<diff; i++) {
            ptr1 = ptr1->next;
        }
    }
    else {
        for(int i=0; i<diff; i++) {
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main() {
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(30);
    Node* head2 = new Node(10);
    head2->next = head1->next->next->next; 
    Node* intersectionNode = getIntersection(head1, head2);
    if(intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection point.\n";
    }
    return 0;
}