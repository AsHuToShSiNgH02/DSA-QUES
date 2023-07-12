#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int val){
        value = val;
        left=right=NULL;
    }
};
int main(){
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);

    cout<<"root node : "<<root->value<<endl;
    cout<<"left node : "<<root->left->value<<endl;
    cout<<"right node : "<<root->right->value<<endl;

    return 0;
}