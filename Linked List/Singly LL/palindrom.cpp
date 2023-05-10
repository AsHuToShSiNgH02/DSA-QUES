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

bool isPalindrom(Node* &head){
    Node* slow = head;
    Node* fast = head;
    //finding middle element
    while(fast->next && fast){
        slow = slow->next;
        fast = fast->next->next;   
    }
    cout<<slow->val<<endl;
    //breaking the node from its middle
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;
    
    //reverse the secong LL
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    //chk if two ll is equal
    Node* head1 = head;
    Node* head2 = prev;

    while(head2){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;

}

int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(3);
    ll.InsertAtTail(2);
    ll.InsertAtTail(1);
    ll.display();
    cout<<isPalindrom(ll.head)<<endl;

    return 0;
}