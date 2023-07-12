#include <iostream>
#include <queue>
#include <vector>
#include <map>
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
vector<int> upperViewbnarytree(Node* rootNode){
    vector<int>ans;
    //base condition
    if(rootNode==NULL){
        return ans;
    }
    
    queue<pair<Node*,int>> q;
    q.push(make_pair(rootNode,0));
    map<int,int>m;

    while(!q.empty()){
        int nodesAtcurrentLevel = q.size();
        while(nodesAtcurrentLevel){
            
            pair<Node*,int>p = q.front();
            Node* currNode = p.first;
            int currCol = p.second;
            q.pop();
            
            if(m.find(currCol)==m.end()){
                m[currCol] = currNode->value;
            }else{
                m[currCol] = currNode->value;
            }
            
            if(currNode->left){
                q.push(make_pair(currNode->left,currCol - 1));
            }

            if(currNode->right){
                q.push(make_pair(currNode->right,currCol + 1));
            }
            nodesAtcurrentLevel--;
        }
        
    }

    for(auto it: m){
        ans.push_back(it.second);
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

    vector<int> ans = upperViewbnarytree(rootNode);
    for(auto i : ans){
        cout<< i <<" ";
    }

    return 0;
}
//       2
//     4  10
//    6 5  11