#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<set<int>>graph;
int v;

void add_edge(int src, int dest,bool bi_drct = true){
    graph[src].insert(dest);
    if(bi_drct){
        graph[dest].insert(src);
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
    graph.resize(v, set<int> ());
    cout<<"Enter the number of edges : "<<endl;
    int e;
    cin>>e;
    while(e--){
        int s ,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    display();
    return 0;
}