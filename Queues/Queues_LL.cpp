#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;
 
 
    Node(int val)
    {
        this->val = val;
    }
};
 
 
class Queue
{
    Node *head = NULL, *tail = NULL;
    int curr_size = 0;
 
 
public:
    void enqueue(int val){
        if (head == NULL){
            head = tail = new Node(val);
            return;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }
 
 
    void dequeue(){
        if (head == NULL){
            cout << "The queue is already empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        curr_size--;
        if (curr_size == 0)
            tail = NULL;
        free(temp);
    }
    int front(){
        if (head == NULL){
            cout << "There is no element in the queue.\n";
            return -1;
        }
        return head->val;
    }
    int size(){
        return curr_size;
    }
 
 
    int isEmpty(){
        return head == NULL;
    }
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);

    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
}
    
