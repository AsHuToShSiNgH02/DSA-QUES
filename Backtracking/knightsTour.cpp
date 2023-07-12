#include <iostream>
#include <vector>
using namespace std;

bool knightsTour(vector<vector<int>> &grid,int i,int j,int n,int cnt){
    //condition to chk where knights cant go
    if(i<0 || j<0 || i>=n ||j>=n||grid[i][j]>=0)return false;
    //once cnt reaches to n*n-1
    if(cnt==(n*n)-1){
        grid[i][j] = cnt;//assinging number to last block
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        return true;
    }

    grid[i][j] =cnt;//assinging cnt to each block

    //chking all the 8 possibility where knight can go
    if(knightsTour(grid,i-1,j-2,n,cnt+1)) return true;
    if(knightsTour(grid,i-2,j-1,n,cnt+1)) return true;
    if(knightsTour(grid,i-1,j+2,n,cnt+1)) return true;
    if(knightsTour(grid,i-2,j+1,n,cnt+1)) return true;
    if(knightsTour(grid,i+1,j-2,n,cnt+1)) return true;
    if(knightsTour(grid,i+2,j-1,n,cnt+1)) return true;
    if(knightsTour(grid,i+1,j+2,n,cnt+1)) return true;
    if(knightsTour(grid,i+2,j+1,n,cnt+1)) return true;
    //if knight cant go anywhere then revert the condition
    grid[i][j]=-1;
    //and return false
    return false;
}
int main(){
    int n = 6;
    vector<vector<int >> grid(n,vector<int>(n,-1));//n*n grid
    knightsTour(grid,0,0,n,0);
    return 0;
}