#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<int,int>>graph;
int v;

void add_edge(int src, int dest,int wt, bool bi_drct = true){
    graph[src][dest] = wt;
    if(bi_drct){
        graph[dest][src] = wt;
    }
}

void display(){
    for(int i = 0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto e: graph[i]){
            cout<<"("<<e.first<<" "<<e.second<<") , ";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Enter the size of vector : "<<endl;
    cin>>v;
    graph.resize(v, unordered_map<int,int> ());
    cout<<"Enter the number of edges : "<<endl;
    int e;
    cin>>e;
    while(e--){
        int s ,d, wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }

    display();
    return 0;
}