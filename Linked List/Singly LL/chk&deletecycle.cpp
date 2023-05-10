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

    void InsertAtTail(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp ->next;
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

bool chkCycle(Node* &head){
    if(!head){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL & fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void deleteCycle(Node* &head){

    Node* slow = head;
    Node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(fast->next != slow->next){
        slow = slow ->next;
        fast = fast -> next;
    }

    slow->next = NULL;
}
int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.InsertAtTail(7);
    ll.InsertAtTail(8);
    ll.display();
    ll.head->next->next->next->next->next->next->next->next = ll.head->next->next;
    
    cout<<chkCycle(ll.head)<<endl;
    deleteCycle(ll.head);
    cout<<"After deletion of cycle : "<<chkCycle(ll.head)<<endl;
    cout<<chkCycle(ll.head)<<endl;

    ll.display();

    return 0;
}