#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>>graph;
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
int main(){
    cout<<"Enter the size of vector : "<<endl;
    cin>>v;
    graph.resize(v, list<int> ());
    cout<<"Enter the number of edges : "<<endl;
    int e;
    cin>>e;
    while(e--){
        int s ,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }

    display();
    return 0;
}