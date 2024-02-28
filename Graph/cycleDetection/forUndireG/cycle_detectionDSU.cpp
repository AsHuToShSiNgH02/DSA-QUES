#include<iostream>
#include<vector>
using namespace std;
//T.c = O(log*n)
int find(vector<int> &parent, int x){
    //returns the parent of group x belongs to
    return parent[x] = (parent[x] == x)? x : find(parent, parent[x]); //path cmpression
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b){
    a = find(parent, a);//parent of a
    b = find(parent, b);//parent of b
    if(a == b) return true;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }else{
        rank[b]++;
        parent[a] = b;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i = 0;i<= n;i++){
        parent[i] = i;
    }

    while(m--){
        int x,  y;
        cin>>x>>y;
        bool b = Union(parent, rank, x, y);
        if(b == true) cout<<"cycle detected";
    }
    return 0;
}