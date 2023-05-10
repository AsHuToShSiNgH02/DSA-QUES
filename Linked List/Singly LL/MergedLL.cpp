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

Node* mergedLL(Node* &head1,Node* &head2){
    Node* dummyHeadNode = new Node(-1);//creating dummy head;
    //creating 3 pointer
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    //comparing the value of both LL and arrenge them into assending order
    while(ptr1 && ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    //in case one of the LL reched to its NULL then all the remaining elemnt of other LL will be linked together
    if(ptr1){
        ptr3->next = ptr1;
    }else{
        ptr3->next = ptr2;
    }
     return dummyHeadNode->next;//return head of dummyLL as excluding temprory vaue(-1)
}

int main(){
    LinkedList ll1;
    ll1.InsertAtTail(1);
    ll1.InsertAtTail(3);
    ll1.InsertAtTail(5);
    ll1.display();

    LinkedList ll2;
    ll2.InsertAtTail(2);
    ll2.InsertAtTail(4);
    ll2.display();

    LinkedList ll3;
    ll3.head = mergedLL(ll1.head,ll2.head);
    ll3.display();

    return 0;
}
