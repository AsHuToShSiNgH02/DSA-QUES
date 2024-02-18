#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; //number of nodes

void add_edge(int src, int dest, bool bi_drct = true){
    graph[src].push_back(dest);
    if(bi_drct){
        graph[dest].push_back(src);
    }
}

void desplay(){
    for(int i = 0;i<graph.size();i++){
       cout<<i<<" -> ";
       for(auto e : graph[i]){
        cout<<e<<", ";
       }
       cout<<endl; 
    }
}

bool dfs(int curr, int dest){
    if(curr == dest)return true;
    visited.insert(curr);//node visited 
    for(auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){
            bool result = dfs(neighbour, dest);
            if(result) return true;
        }
    }
    return false;
}

bool any_path(int start , int end){
    return dfs(start, end);
}

int main(){
    cout<<"Enter the no of nodes :";
    cin>>v;
    graph.resize(v, list<int>());
    cout<<"Enter the no of edges :";
    int e;
    cin>>e;
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edge(src ,dest);
    }
    desplay();

    cout<<"Enter the src and dest for path :";
    int s ,d;
    cin>>s>>d;
    cout<<any_path(s,d)<<endl;

    return 0;
}