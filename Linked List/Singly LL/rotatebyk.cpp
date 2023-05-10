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

Node* rotateByK(Node* &head,int k){
    int n = 0;

    Node* tail = head;
    while(tail->next!=NULL){
        n++;
        tail = tail->next;
    }
    n++;//to count the last node
    tail->next = head;
    k = k%n;
    if(k==0){
        return head;
    }
    Node*temp = head;
    for(int i = 1;i<n-k;i++){
        temp = temp->next;
    }
    Node* newhead = temp->next;
    temp->next = NULL;
    return newhead;
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

    ll.head = rotateByK(ll.head,3);
    ll.display();

    return 0;
}