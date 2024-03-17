#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <limits.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
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
        for(auto e: graph[i]){
            cout<<e<<" , ";
        }
        cout<<endl;
    }
}

void bfs(int src ,vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(!qu.empty()){
        int curr = qu.front();
        // cout<<curr<<" ";
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(!visited.count(neighbour)){
                visited.insert(neighbour);
                qu.push(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<endl;
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
    display();
    int s;
    cin>>s;
    vector<int>dist;
    bfs(s, dist);
    for(auto e:dist){
        cout<<e<<" ";
    }
    return 0;
}