#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp> >gr;
void add_edge(int u ,int v, int wt, bool bidir = true){
    gr[u].push_back({v, wt});
    if(bidir) {
        gr[v].push_back({u,wt});
    }
} 

ll prims(int src, int n){                             // O(vlogV + ElogV)
    priority_queue<pp, vector<pp> ,greater<pp> > pq;  //store node and wt to reach the node
    //{wt, node}
    unordered_set<int> vis;                           // mark the node visited
    vector<int> par(n+1);                             // stores the parent(here n+1 for 1 based indexing)
    unordered_map<int, int> mp;                       // stores node and and min wt to reach the node 
    for(int i = 1;i<=n;i++){                          // bcoz no dicovery is yet done
        mp[i] = INT_MAX;
    }
    pq.push({0, src});                                // pushing src with finding wt 0
    mp[src] = 0;                                      // initializing src with 0 wt
    int total_count = 0;                              // 0 -> n-1 edgest
    int result = 0;
    while(total_count < n && !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)) {                  //curr vis jzt continue
            pq.pop();
            continue;
        }
        vis.insert(curr.second);                      // if not vis insert it in vis.insert
        total_count++;                                // increase edges count
        result += curr.first;                         // add up the edge
        pq.pop();
        for(auto neighbour : gr[curr.second]) {       //cheking out all neighbour fo curr
            if(!vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second){  //if not visited and wt to reach node is smaller than the priv one
                pq.push({neighbour.second, neighbour.first});  //push in pq
                par[neighbour.first] = curr.second;            //update par vector
                mp[neighbour.first] = neighbour.second;        // update mp with new weight
            }
        }
    }
    return result;                                              
}

int main(){
    int n , m;
    cin>>n>>m;
    gr.resize(n+1, list<pp>());
    while(m--){
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    cout<<prims(src, n)<<"\n";
    return 0;
}