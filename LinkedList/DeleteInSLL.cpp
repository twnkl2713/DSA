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

Node* deleteHead(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteNthNode(Node* head, int n) {
    if(n <= 0 || head == NULL) return head;
    if(n == 1) return deleteHead(head);
    int count = 1;
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL) {
        if(count == n) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}

Node* removeElement(Node* head, int val) {
    if(head == NULL) return head;
    while(head != NULL && head->data == val) {
        head = deleteHead(head);
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp->data == val) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

Node* deleteLinkedList(Node* head) {
    Node* temp = head;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}   

Node* deleteNthNodeFromEnd(Node* head, int n) {
    if(head == NULL || n <= 0) return head;
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    if(n == count) {
        return deleteHead(head);
    }
    Node* ptr = head;
    for(int i=0; i<count-n-1 && ptr!=NULL; i++) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    ptr->next = temp->next;
    free(temp);
    return head;
}

Node* deleteLinkedListRecursively(Node* head) {
    if(head == NULL) return NULL;
    deleteLinkedListRecursively(head->next);
    free(head);
    return NULL;
}

Node* deleteMiddleNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    if(head->next->next == NULL) {
        free(head->next);
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow will point to middle-1 node
    Node* middle = slow->next;
    slow->next = middle->next;
    middle->next = NULL;
    free(middle);
    return head;
}

int main() {
    Node* head = nullptr;
    int choice, value, n;
    do {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete Head\n";
        cout << "3. Delete Tail\n";
        cout << "4. Delete Nth Node\n";
        cout << "5. Remove Element by Value\n";
        cout << "6. Delete Nth Node from End\n";
        cout << "7. Delete Middle Node\n";
        cout << "8. Delete Entire Linked List\n";
        cout << "9. Print Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                {
                    Node* newNode = new Node(value);
                    if(head == nullptr) {
                        head = newNode;
                    } else {
                        Node* temp = head;
                        while(temp->next != nullptr) temp = temp->next;
                        temp->next = newNode;
                    }
                }
                break;

            case 2:
                head = deleteHead(head);
                cout << "Head deleted.\n";
                break;

            case 3:
                head = deleteTail(head);
                cout << "Tail deleted.\n";
                break;

            case 4:
                cout << "Enter position to delete: ";
                cin >> n;
                head = deleteNthNode(head, n);
                cout << "Node deleted at position " << n << ".\n";
                break;

            case 5:
                cout << "Enter value to remove: ";
                cin >> value;
                head = removeElement(head, value);
                cout << "All occurrences of " << value << " removed.\n";
                break;

            case 6:
                cout << "Enter position from end to delete: ";
                cin >> n;
                head = deleteNthNodeFromEnd(head, n);
                cout << "Node deleted from position " << n << " from end.\n";
                break;

            case 7:
                head = deleteMiddleNode(head);
                cout << "Middle node deleted.\n";
                break;

            case 8:
                head = deleteLinkedList(head);
                cout << "Entire linked list deleted.\n";
                break;

            case 9:
                if(head == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    Node* temp = head;
                    cout << "Linked List: ";
                    while(temp != nullptr) {
                        cout << temp->data << " -> ";
                        temp = temp->next;
                    }
                    cout << "NULL\n";
                }
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 0);
    head = deleteLinkedList(head);
    return 0;
}