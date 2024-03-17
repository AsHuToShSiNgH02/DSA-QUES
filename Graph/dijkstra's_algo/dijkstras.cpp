#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

vector<list<pp> >gr;
void add_edge(int u ,int v, int wt, bool bidir = true){
    gr[u].push_back({v, wt}); 
    if(bidir) {
        gr[v].push_back({u,wt});
    }
} 

unordered_map <int, int> djikstra(int src, int n){     //O(vlogV + ElogV)
    priority_queue<pp, vector<pp> ,greater<pp> > pq;  //store node and wt to reach the node
    //{wt, node}
    unordered_set<int> vis;                           // mark the node visited
    vector<int> via(n);                             // stores the parent(here n+1 for 1 based indexing)
    unordered_map<int, int> mp;                       // stores node and and min wt to reach the node 
    for(int i = 0;i<n;i++){                          // bcoz no dicovery is yet done
        mp[i] = numeric_limits<int>::max();
    }
    pq.push({0, src});                                // pushing src with finding wt 0
    mp[src] = 0;                                      // initializing src with 0 wt
    
    while(!pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)) {                  //curr vis jzt continue
            pq.pop();
            continue;
        }
        vis.insert(curr.second);                      // if not vis insert it in vis.insert                         // add up the edge
        pq.pop();
        for(auto neighbour : gr[curr.second]) {       //cheking out all neighbour fo curr
            if(!vis.count(neighbour.first) and mp[neighbour.first] > (neighbour.second + mp[curr.second])){  //if not visited and wt to reach node is smaller than the priv one
                pq.push({neighbour.second + mp[curr.second], neighbour.first});  //push in pq
                via[neighbour.first] = curr.second;            //update par vector
                mp[neighbour.first] = neighbour.second + mp[curr.second];        // update mp with new weight
            }
        }
    }
    
    return mp;

}

int main(){
    int n , m;
    cin>>n>>m;
    gr.resize(n, list<pp>());
    while(m--){
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    unordered_map<int, int> sp = djikstra(src, n);
    for(auto el : sp){
        cout<<el.first<<" "<<el.second<<endl;
    }
    int dest;
    cin>>dest;
    cout<<sp[dest]<<"\n";
    return 0;
}