#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next; //will store address of nxt node

    Node(int data){
        val = data;
        next = NULL;//null means LL will get termnated,no address is provided for nxt node
    }
};

int main(){
    Node* n = new Node(1); // creating pointer variable to pass value to first node
    cout<<n->val<<" "<<n->next<<endl;//printing val and address stored in first node

    return 0;
}