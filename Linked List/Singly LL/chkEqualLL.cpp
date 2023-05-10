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
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

bool CheckEqualLL(Node* &head1,Node* &head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val != temp2->val){
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1 == NULL && temp2 == NULL){
        return 1;
    }
}
int main(){
    LinkedList ll1;
    ll1.InsertAtTail(1);
    ll1.InsertAtTail(2);
    ll1.InsertAtTail(3);
    ll1.InsertAtTail(5);
    ll1.InsertAtTail(5);
    ll1.InsertAtTail(6);
    
    
    LinkedList ll2;
    ll2.InsertAtTail(1);
    ll2.InsertAtTail(2);
    ll2.InsertAtTail(3);
    ll2.InsertAtTail(4);
    ll2.InsertAtTail(5);
    ll2.InsertAtTail(6);

    ll1.display();
    ll2.display();

    cout<<CheckEqualLL(ll1.head,ll2.head);
    

    return 0;
}