#include <iostream>
#include <vector>
using namespace std;

bool canWeGo(int i ,int j ,vector<vector<int>> & grid){
    //chking if rat is allowed to go in next block or not
    return (i < grid.size() && j < grid.size() && i >= 0 && j >= 0) && grid[i][j]==1;
}
int ratInMace(int i,int j, vector<vector<int>> & grid){
    int n = grid.size();
    //base condition
    if(i==(n-1) && j==(n-1)) return 1;
    
    //ans variable will store the no of path
    int ans = 0;
    //mark so that rat can not travell same path again
    grid[i][j] = 2;
    
    if(canWeGo(i,j+1,grid)) //right
        //keep adding ans once it found new path
        ans+=ratInMace(i,j+1,grid);
    
    if(canWeGo(i+1,j,grid))  //down
        ans+=ratInMace(i+1,j,grid);

    if(canWeGo(i,j-1,grid))  // left
        ans+=ratInMace(i,j-1,grid);

    if(canWeGo(i-1,j,grid))  //up 
        ans+=ratInMace(i-1,j,grid);
    
    //revert the mark so that new paths can be discovered
    grid[i][j] = 1;
    return ans;
    
}
int main(){
    vector<vector<int>>grid{
        {1,1,1,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,1}
    };
    int res = ratInMace(0,0,grid);
    cout<<res<<"\n";
    return 0;
}