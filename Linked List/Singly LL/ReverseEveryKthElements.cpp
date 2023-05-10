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
        // if(head == NULL){
        //     head = new_node;
        //     return;
        // }
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

Node* reverseLL(Node* &head,int k){
    Node* priv = NULL;
    Node* curr = head;
    
    int count = 0;
    while(curr != NULL && count<k){ //REVERSING THE LIST TILL EVERY K POSITION
        Node* next = curr->next;
        curr->next = priv;
        priv=curr;
        curr=next;
        count++;
    }
    if(curr!=NULL){
        Node* new_head = reverseLL(curr,k);//when count>k then curr pointer will act as head for next set of K element
        head->next = new_head;//linking priv head with new head
    }
    
    Node* EveryKth_head = priv;
    return EveryKth_head; //returning priv bcoz it will be new head for every set of K element
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

    ll.head = reverseLL(ll.head,2);
    ll.display();

    return 0;
}