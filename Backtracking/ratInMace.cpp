/* In 2D Matrix rat can go (upward,downward,forward,backward), find the number of ways that Rat can reach
from upper left block to lower right block
conditions: 
rat can not move in 0 marked block it can only go through 1 marked block*/
#include <iostream>
#include <vector>
using namespace std;

bool CanWeGo(int i ,int j,vector<vector<int>> &grid){
    return (i < grid.size() && j < grid.size() && i >= 0 && j >= 0) && grid[i][j] == 1;
}
int NoOfPaths(int i,int j,vector<vector<int>> &grid){
    int n = grid.size();
    //Base case
    if(i == n-1 && j == n-1){
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<n;i++){
        //         cout<<grid[i][j]<<" ";                
        //     }cout<<endl;
        // }
        // cout<<"****";
        return 1;
    }

    int ans = 0;
    grid[i][j] = 2;
    if(CanWeGo(i,j+1,grid)){//forward
        ans += NoOfPaths(i,j+1,grid);
    }
    if(CanWeGo(i+1,j,grid)){//downward
        ans += NoOfPaths(i+1,j,grid);
    }
    if(CanWeGo(i,j-1,grid)){//backward
        ans += NoOfPaths(i,j-1,grid);
    }
    if(CanWeGo(i-1,j,grid)){//upward
        ans += NoOfPaths(i-1,j,grid);
    }
    grid[i][j] == 1;
    return ans;
}
int main(){
    vector<vector<int>> grid = {
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };

    int res = NoOfPaths(0,0,grid);
    cout<<res<<"\n";
    return 0;
}
