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
        while(temp->next!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

void deleteDuplicate(Node* &head){
    Node *curr_pos = head;
    while(curr_pos->next != NULL && curr_pos != NULL){
        if(curr_pos->val == curr_pos->next->val){
            Node* temp = curr_pos->next;
            curr_pos->next = curr_pos->next->next;
            free(temp);
        }
        curr_pos = curr_pos->next;
    }
}
int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(3);
    ll.InsertAtTail(3);
    ll.display();

    deleteDuplicate(ll.head);
    ll.display();
}