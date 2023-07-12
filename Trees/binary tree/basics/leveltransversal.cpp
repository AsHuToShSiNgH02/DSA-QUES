#include <iostream>
#include <queue>
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
void levelorderTransversal(Node* rootNode){
    //base condition
    if(rootNode==NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){
        int nodesAtcurrentLevel = q.size();
        while(nodesAtcurrentLevel--){

            Node* currNode = q.front();
            q.pop();
            cout<<currNode->value<<" ";
            if(currNode->left){
                q.push(currNode->left);
            }

            if(currNode->right){
                q.push(currNode->right);
            }
        }
        cout<<endl;
    }
}
int main(){
    Node *rootNode = new Node(2);
    rootNode->left=new Node(4);
    rootNode->left->left= new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right = new Node(10);
    rootNode->right->right=new Node(11);

    levelorderTransversal(rootNode);

    return 0;
}
//       2
//     4  10
//    6 5  11