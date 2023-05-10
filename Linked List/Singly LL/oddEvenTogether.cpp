#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int value){
        val = value;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void InsertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

Node* oddEvenLL(Node* &head){
    if(!head){//chking if single linked list is present
        return head;
    }

    Node* evenHead = head->next;
    Node* oddptr = head;
    Node* evenptr = evenHead;

    while(evenptr && evenptr->next){
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }
    
    oddptr->next = evenHead;
    return head;
}

int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.display();

    ll.head = oddEvenLL(ll.head);
    ll.display();
    

    return 0;
}