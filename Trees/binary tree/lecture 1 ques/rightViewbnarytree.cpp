#include <iostream>
#include <queue>
#include <vector>
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
vector<int> rightViewbnarytree(Node* rootNode){
    vector<int>ans;
    //base condition
    if(rootNode==NULL){
        return ans;
    }
    
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){
        int nodesAtcurrentLevel = q.size();
        while(nodesAtcurrentLevel){

            Node* currNode = q.front();
            q.pop();
/*LOGIC : in levelorder transversal in each level we transverse from left to right means last element
will we be right most element therfore when the nodesAtcurrentLevel becomes 1 it means it is right
element we need so we will push it to ans vector*/
            if(nodesAtcurrentLevel==1){
                ans.push_back(currNode->value);
            }
            if(currNode->left){
                q.push(currNode->left);
            }

            if(currNode->right){
                q.push(currNode->right);
            }
            nodesAtcurrentLevel--;
        }
        
    }
    return ans;
}
int main(){
    Node *rootNode = new Node(2);
    rootNode->left=new Node(4);
    rootNode->left->left= new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right = new Node(10);
    rootNode->right->right=new Node(11);

    vector<int> ans = rightViewbnarytree(rootNode);
    for(auto i : ans){
        cout<< i <<" ";
    }

    return 0;
}
//       2
//     4  10
//    6 5  11