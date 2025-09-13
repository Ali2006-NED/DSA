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

bool PalindromeCheck(Node*head){

    if(head == NULL || head->next == NULL) return true;

    // Step 1: Find middle node
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    Node*prev = NULL;
    Node*curr = slow->next;
    Node*nextptr;

    while(curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }

    // Step 3: Compare first half and second reversed half
    Node* p1 = head;
    Node* p2 = prev;

    while(p2 != NULL){
        if(p1->data != p2->data) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;

}

int main(){

    Node* head = new Node(6);
    head->next = new Node(5);
    head->next->next = new Node(5);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(6);





    cout << PalindromeCheck(head);
    
    return 0;
}