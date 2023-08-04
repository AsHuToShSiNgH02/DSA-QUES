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
vector<int> leftViewbnarytree(Node* rootNode){
    vector<int>ans;
    //base condition
    if(rootNode==NULL){
        return ans;
    }
    
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){
        int nodesAtcurrentLevel = q.size();
        // ans.push_back(q.front()->value);
        while(nodesAtcurrentLevel){

            Node* currNode = q.front();
            q.pop();
/*LOGIC : same as right view we will just insert right element first */
            if(nodesAtcurrentLevel==1){
                ans.push_back(currNode->value);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            if(currNode->left){
                q.push(currNode->left);
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
    rootNode->left->right->right = new Node(3);
    rootNode->right->right->right =new Node(12);
    rootNode->right->right->right->right =new Node(1);
    vector<int> ans = leftViewbnarytree(rootNode);
    for(auto i : ans){
        cout<< i <<" ";
    }

    return 0;
}
//       2
//     4   10
//    6 5    11
//       3     12
//               1