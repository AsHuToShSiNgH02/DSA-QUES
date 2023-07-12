#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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
vector<int> reverseLevelOrder(Node* rootNode){
    vector<int>ans;
    //base condition
    if(rootNode==NULL){
        return ans;
    }
    
    queue<Node*> q;
    stack<Node*> s;
    q.push(rootNode);

    while(!q.empty()){
        int nodesAtcurrentLevel = q.size();
        while(nodesAtcurrentLevel--){
            
            Node* currNode = q.front();
            q.pop();
            s.push(currNode);//push node in stack
            
            if(currNode->right){
                q.push(currNode->right);
            }

            if(currNode->left){
                q.push(currNode->left);
            }
            
        }

    }

    while(!s.empty()){
        ans.push_back(s.top()->value);
        s.pop();
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

    vector<int> ans = reverseLevelOrder(rootNode);
    for(auto i : ans){
        cout<< i <<" ";
    }

    return 0;
}
//       2
//     4  10
//    6 5  11