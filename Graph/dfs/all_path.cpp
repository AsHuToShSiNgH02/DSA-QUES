#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>>graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;

void add_edge(int src, int dest, bool bi_drct = true){
    graph[src].push_back(dest);
    if(bi_drct){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto e : graph[i]){
            cout<<e<<", ";
        }
        cout<<endl;
    }
}

void dfs(int curr, int end, vector<int> &path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour: graph[curr]){
        if(!visited.count(neighbour)){
            dfs(neighbour, end ,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void all_path(int start, int end){
    vector<int> v;
    bfs(start, end, v);
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edge(src, dest);
    }
    // display();
    int s, d;
    cin>>s>>d;
    all_path(s,d);
    for(auto path: result){
        for(auto el: path){
            cout<<el<<", ";
        }
        cout<<endl;
    }
    return 0;
}