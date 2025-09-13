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

int LinkedListSize(Node*head){

    int size = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}
Node* DeletefromLast(Node*head,int n){

    int size = LinkedListSize(head);

    int pos = size - n;
    
    if(size == n){
        Node*newhead = head->next;
        delete head;
        return newhead;
    }
    Node* temp = head;
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return head;

}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    head = DeletefromLast(head,1);

    printList(head);


    return 0;
}