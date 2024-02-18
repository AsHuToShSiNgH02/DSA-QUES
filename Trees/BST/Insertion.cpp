#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
            cout<<currNode->data<<" ";
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
Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d < root->data) root->left = insertIntoBST(root->left,d);
    else root->right = insertIntoBST(root->right, d);
    return root;
}
void inputData(Node* &root){
    int d;
    cin>>d;
    while(d != -1){
        insertIntoBST(root, d);
        cin>>d;
    }
}
int main(){
    Node* root = NULL;

    cout<<"Enter the data of Nodes : "<<endl;
    inputData(root);

    cout<<"Given tree is: "<<endl;
    levelorderTransversal(root);

    return 0;
}