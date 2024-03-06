#include<bits/stc++.h>

using namespace std;

class Solution {
public:
    int find(vector<int> &parent, int a){
        return parent[a] = (parent[a] == a)? a : find(parent, parent[a]);
    }

    void Union(vector<int> &parent,vector<int> &rank, int a, int b){
        a = find(parent, a);
        b = find(parent, b);
        if(rank[a] >= rank[b]){
            rank[a]++;
            parent[b] = a;
        }else{
            rank[b]++;
            parent[a] = b;
        }
    }
    struct Edge{
        int src;
        int dest;
        int wt;
    };

    static bool cmp(Edge e1, Edge e2){
        return e1.wt < e2.wt;
    }
    
    // void graphImp(vector<vector<int>>& points){
        
    // }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> graph;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int x = abs(points[i][0] - points[j][0]);
                int y = abs(points[i][1] - points[j][1]);
                int wt = x + y;
                graph.push_back(Edge{i, j, wt});
            }
        }
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        } //inititalizing parent array from 0 to n-1;
        sort(graph.begin(),graph.end(),cmp);
        
        int sum = 0;

        for(int i = 0;i<graph.size();i++){
            Edge curr = graph[i];
            int srcPar = find(parent,curr.src);
            int destPar = find(parent,curr.dest);

            if(srcPar != destPar) {
                sum += curr.wt;
                Union(parent, rank ,srcPar, destPar);
            }
        }
        return sum;
    }
};


int main(){
    
    return 0;
}