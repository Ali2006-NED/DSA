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
Node* ReverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nextptr;
    while(curr != NULL){
        nextptr = curr->next; // Store next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr; // Store the current state of reversed list
        curr = nextptr; // update curr to next node
    }
    return prev; // return new head of the reversed list
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    head = ReverseList(head);
    printList(head);


    
    return 0;
}