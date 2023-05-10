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
int getlength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp->next != NULL){
        length++;
        temp = temp->next;
        
    }
    return length;
}
Node* moveAheadByK(Node* &head, int k){
    Node* temp = head;
    while(k--){
        temp = temp->next;
    }
    return temp;
}

Node* GetIntersection(Node* &head1,Node* &head2){
    int l1 = getlength(head1);
    int l2 = getlength(head2);
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if(l1>l2){
        int k = l1 - l2;
        ptr1 = moveAheadByK(head1,k);
        ptr2 = head2;
    }else{
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveAheadByK(head2,k);
    }

    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
 }

int main(){
    LinkedList ll1;
    ll1.InsertAtTail(1);
    ll1.InsertAtTail(2);
    ll1.InsertAtTail(3);
    ll1.InsertAtTail(4);
    ll1.InsertAtTail(5);
    ll1.InsertAtTail(6);
    
    
    LinkedList ll2;
    ll2.InsertAtTail(1);
    ll2.InsertAtTail(2);
    ll2.head->next->next = ll1.head->next->next->next;
    
    ll1.display();
    ll2.display();
    Node* Intersection = GetIntersection(ll1.head,ll2.head);
    if(Intersection){
        cout<<Intersection->val<<endl;
    }else{
         cout<<"-1"<<endl;
    }
    

    return 0;
}