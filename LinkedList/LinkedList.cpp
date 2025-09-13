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

Node* insertAtBeginning(Node*head, int value){
    Node* newnode = new Node(value);
    newnode->next = head;
    return newnode;
}
Node* deleteTail(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;

}

Node* ReverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nextptr;

    while(curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    cout<<"Original List: ";
    printList(head);
    
    // head = deleteTail(head);
    // cout<<"After Deletion at Tail: ";
    // printList(head);

    head = ReverseList(head);
    cout<<"After Reversing the List: "; 
    printList(head);

    return 0;
}