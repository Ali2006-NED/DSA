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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* ReverseSegment(Node* head, int start, int end) {
    if (!head || start == end) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prevStart = dummy;

    // Move prevStart to node before start
    for (int i = 0; i < start; i++) {
        prevStart = prevStart->next;
    }

    Node* temp1 = prevStart->next;   // first node in segment
    

    for (int i = start; i < end; i++) {
        Node* nextptr = temp1->next;
        temp1->next = nextptr->next;
        nextptr->next = prevStart->next;
        prevStart->next = nextptr;
    }

    return dummy->next;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = ReverseSegment(head, 0, 1);  
    cout << "Reversed: ";
    printList(head);

    return 0;
}
