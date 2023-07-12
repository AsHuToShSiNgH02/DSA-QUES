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
void postorderTransversal(Node* rootNode){
    //base condition
    if(rootNode==NULL){
        return;
    }
    
    //recursive
    postorderTransversal(rootNode->left);
    postorderTransversal(rootNode->right);
    cout<<rootNode->value<<" ";
}
int main(){
    Node *rootNode = new Node(2);
    rootNode->left=new Node(4);
    rootNode->left->left= new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right = new Node(10);
    rootNode->right->right=new Node(11);

    postorderTransversal(rootNode);

    return 0;
}
//       2
//     4  10
//    6 5  11