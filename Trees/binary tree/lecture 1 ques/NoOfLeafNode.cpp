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
int leafNode(Node* rootNode){
    //base condition
    if(rootNode==NULL){
        return 0;
    }
    if(rootNode->left==NULL && rootNode->right==NULL) return 1;
    
    int leftleafNode = leafNode(rootNode->left);
    int rightleafNode = leafNode(rootNode->right);
    
    return(leftleafNode + rightleafNode);
}
int main(){
    Node *rootNode = new Node(2);
    rootNode->left=new Node(4);
    rootNode->left->left= new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right = new Node(10);
    rootNode->right->right=new Node(11);
    rootNode->right->left = new Node(12);

    cout<<leafNode(rootNode)<<endl;

    return 0;
}
//       2
//    4      10
//  6   5  4    11