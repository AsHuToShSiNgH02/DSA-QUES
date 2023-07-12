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
void preorderTransversal(Node* rootNode){
    //base condition
    if(rootNode==NULL){
        return;
    }
    cout<<rootNode->value<<" ";
    //recursive
    preorderTransversal(rootNode->left);
    preorderTransversal(rootNode->right);
}
int main(){
    Node *rootNode = new Node(2);
    rootNode->left=new Node(4);
    rootNode->left->left= new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right = new Node(10);
    rootNode->right->right=new Node(11);

    preorderTransversal(rootNode);

    return 0;
}
//       2
//     4  10
//    6 5  11