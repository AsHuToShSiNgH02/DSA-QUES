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

Node* reorderLL(Node* &head){
    //find middle elemnt
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //slow is pointing to the middle element
    //reversing the secong ll
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;
    while(curr){
        Node* nxtnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxtnode;
    }

    //rearranging the ll
    Node* ptr1 = head;
    Node* ptr2 = prev;
    while(ptr1!=ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    } 

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
    ll.head = reorderLL(ll.head);
    ll.display();

    return 0;
}