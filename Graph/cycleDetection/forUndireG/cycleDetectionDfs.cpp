#include <bits/stdc++.h>   
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

bool dfs(int src, int parent){
    visited.insert(src);//node visited 
    for(auto neighbour : graph[src]){
        if(!visited.count(neighbour) and neighbour != parent){
            //cycle detected
            return true;
        }
        if(!visited.count(neighbour)){
            bool result = dfs(neighbour, parent);
            if(result) return true;
        }
    }
    return false;
}

bool has_Cycle(){
    for(int i =0;i<v;i++){
        if(!visited.count(i)){
            bool result = dfs(i, -1);
            if(result = true) return  true;
        }
    }
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

    cout<<has_Cycle()<<endl;

    return 0;
}