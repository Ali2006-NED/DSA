#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    while (curr && curr->next) {
        Node* nextPair = curr->next->next; // 1->2->3->4->5 nextPair = 3
        Node* second = curr->next; // 1->2->3->4->5 second = 2

        // Swapping
        second->next = curr; // curr = 1, second = 2       2->1
        curr->next = nextPair; // curr = 1, nextPair = 3   1->3
        prev->next = second; // prev = 0, second = 2       0->2

        // Re-positioning prev and curr for next swap
        prev = curr; // prev = 1
        curr = nextPair; // curr = 3
    }
    return dummy->next;

    }

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = swapPairs(head);
    printList(head);

    
    return 0;
}