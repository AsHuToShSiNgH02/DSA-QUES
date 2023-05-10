#include <iostream>
using namespace std;

class Node{ //creating Node
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};
/*
T.C. = O(1)
S.C. = O(1)
*/
void InsertNodeAtHead(Node* &head, int val){ //inserting new node at head
    Node* new_node = new Node(val);//creating new node
    new_node->next = head;//then ponting the adress in new node to head node
    head = new_node;//now shifting the head pointer to new_node
}
/*
T.C. = O(n)
S.C. = O(1)
*/
void InsertNodeAtTail(Node* &head, int val){ //inserting new node at tail
    Node* new_node = new Node(val);//making new node
    Node* temp = head; //pointing temp pointer to head pointer
    while(temp->next != NULL){//treansversing till node adress is pointing to NULL
        temp = temp->next;
    }
    //temp is now pointing to the tail
    temp->next = new_node; //insert the pointer
}
/*
T.C. = O(n)
S.C. = O(1)
*/
void InsertNodeAtKpos(Node* &head, int val, int pos){//inserting node at K position
    if(pos == 0){
        InsertNodeAtHead(head,val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != pos-1){
        temp=temp->next;
        curr_pos++;
    }
    //temp is pointing to the node before pos
    new_node->next = temp->next;//bcoz now new node will point to the node which was previously pointed by temp node
    temp->next = new_node;//now temp will point to new node;
}
/*
T.C. = O(n)
S.C. = O(1)
*/
void updatePos(Node* &head,int pos,int val){//updating value at k pos
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != pos){
        temp = temp->next;
        curr_pos++;
    }
    //temp is pointing to the k pos
    temp->val = val;
}

void deleatAhead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* second_last = head;
    while(second_last->next->next != NULL){
        second_last = second_last->next;
    }

    //second last is pointing to second last node
    Node *temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

void deleteKelmnt(Node* &head,int pos){
    if(pos == 0){
        deleatAhead(head);
    }

    Node* prev = head;
    int current_pos = 0;
    while(current_pos != pos-1){
        prev = prev->next;
        current_pos++;
    }
    //now current pos is pointin to the node which we want to delete
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}
void display(Node* head){ // tranversing in LL
    Node* temp = head;//crating new pointer that point head
    while(temp!=NULL){ //moving temp pointer through LL
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;//intializing node
    InsertNodeAtHead(head,2);
    display(head);
    InsertNodeAtHead(head,1);
    display(head);
    InsertNodeAtTail(head,3);
    display(head);
    InsertNodeAtKpos(head,4,1);
    display(head);
    updatePos(head,2,5);
    display(head);
    deleatAhead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteKelmnt(head,1);
    display(head);
    
    return 0;
}