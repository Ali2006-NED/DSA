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

void DeleteTail(Node*head){
    while(head->next->next != NULL){
        head = head->next;
    }
    delete head->next;
    head->next = NULL;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    DeleteTail(head);
    printList(head);

    int size = 0;
    Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
    cout << "Size of linked list is: " << size+1 << endl;

    
    return 0;
}