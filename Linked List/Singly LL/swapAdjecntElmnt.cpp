#include <iostream>
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

    void InserElmtnAtTail(int value){
        Node* new_node = new Node(value);
        if(head==NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp -> next;
        }
        temp ->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

Node* swapAddjecntNode(Node* &head){
    //base case
    if(head==NULL || head->next == NULL){
        return head;
    }
    //recursive fucntion 
    Node* secondNode = head->next;
    head->next = swapAddjecntNode(secondNode->next);
    secondNode->next = head;
    return secondNode;
}

int main(){
    LinkedList ll;
    ll.InserElmtnAtTail(1);
    ll.InserElmtnAtTail(2);
    ll.InserElmtnAtTail(3);
    ll.InserElmtnAtTail(4);
    ll.InserElmtnAtTail(5);
    ll.InserElmtnAtTail(6);
    ll.display();

    ll.head = swapAddjecntNode(ll.head);
    ll.display();

    return 0;
}