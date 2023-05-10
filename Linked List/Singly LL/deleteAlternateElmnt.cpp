#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
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
        while(temp != NULL){
           cout<<temp->val<<"->";
           temp = temp -> next;
        }cout<<"NULL"<<endl;
    }
};

void deleteAlternateE(Node* &head){
    Node* current_pos = head;
    
    while(current_pos->next != NULL && current_pos != NULL){
        Node* temp = current_pos->next;
        current_pos->next=current_pos->next->next;
        free(temp);
        current_pos = current_pos->next;
    }
}

int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);

    ll.display();
    cout<<"Deleated : ";
    deleteAlternateE(ll.head);
    ll.display();



}