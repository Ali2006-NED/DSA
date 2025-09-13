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

Node* sortList(Node* head) {
        if(!head || !head->next) return head;

        
        Node*curr = head;
        Node*temp = head;

        while(temp != nullptr){

        while(curr->next != nullptr){
            if(curr->data > curr->next->data){
                swap(curr->data,curr->next->data);
            }
            else curr = curr->next;
        }
        temp = temp->next;
        }
        return head;
    }

int main(){

     Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = sortList(head);
    printList(head);
    return 0;
}