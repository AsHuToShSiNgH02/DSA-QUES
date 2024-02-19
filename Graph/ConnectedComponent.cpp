#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src ,int dest ,bool bi_dirt = true){
    graph[src].push_back(dest);
    if(bi_dirt){
        graph[dest].push_back(src);
    }
}

void dfs(int src, unordered_set<int> &visited){
    visited.insert(src);
    for(auto neighbour: graph[src]){
        if(!visited.count(neighbour)){
            dfs(neighbour,visited);
        }
    }
}

int connected_component(){
    int result = 0;
    unordered_set<int> visited;
    for(int i = 0;i<v;i++){
        //go to every vertex
        //if from any vertex we can initialize new dfs, we got one more cc
        if(visited.count(i) == 0){
            result++;
            dfs(i, visited);
        }
    }
    return result;
}
int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int src ,dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    cout<<connected_component()<<endl;
    return 0;
}