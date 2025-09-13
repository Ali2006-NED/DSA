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

Node* printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtIndex(Node*&head,int index,int value){
    Node* newnode = new Node(value);
    if(index == 0) {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node* prev = head;
    while(index != 0 && head != NULL){
        prev = head;
        head = head->next;
        index--;
    }
    newnode->next = head;
    prev->next = newnode;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    insertAtIndex(head,0,15);
    printList(head);

    return 0;
}