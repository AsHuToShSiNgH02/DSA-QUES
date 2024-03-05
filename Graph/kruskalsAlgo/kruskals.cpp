#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;

int find(vector<int> &parent, int a){
    return parent[a] = ((parent[a] == a) ? a : find(parent,parent[a]));
}

void Union(vector<int> &par, vector<int> &rank, int a, int b){
    a = find(par, a);
    b = find(par, b);
    if(a == b) return;
    if(rank[a] >= rank[b]){ 
        rank[a]++;
        par[b] = a;
    }else{
        rank[b]++;
        par[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

ll Kruskals(vector<Edge> &input, int n, int  e){   //O(V + elog(e))
    sort(input.begin(),input.end(),cmp); //sorted according  to cmp //O(Eln(E))
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
                                      
    ll ans = 0;
    int edgeCount = 0; //n -1
    int i =  0;
    while(edgeCount < n-1 and i < input.size()){// V-1   //O(V LOG*V)
        Edge curr = input[i]; //becoz input is sorted so we well get min we edge
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){
            //include edges as this will not make cycle
            Union(parent,rank,srcPar,destPar);
            ans += curr.wt;
            edgeCount++;                                  
        }
        i++; //doesnt matter we picked the last edge or not we still need to go to next edge
    }
    return ans;
}
int main(){
    int n,e;
    cin>>n>>e;
    //creating edge list
    vector<Edge> v(e);
    for(int i = 0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<< Kruskals(v, n ,e)<<endl;
    return 0;
}