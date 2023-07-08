#include <iostream>
#include <vector>
using namespace std;

bool canPlaceQueen(int row,int col,vector<vector<char>> &grid){
    //is queen attacking from verticle up
    for(int i = row -1;i>=0;i--){
        if(grid[i][col]=='Q'){
            return false;
        }
    }
    //from diagonal left
    for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    //from diagonal right
    for(int i = row-1,j=col+1;i>=0 && j<grid.size();i--,j++){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nQueen(int currRow,int n,vector<vector<char>> &grid){
    //base condition
    //is currRow = size of grid?
    if(currRow == n){
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"***"<<endl;
    }
    
    //iterate through each col in each row
    for(int col = 0;col<n;col++){
        //chk weather we can place Q or not
        if(canPlaceQueen(currRow,col,grid)){
            //if we can the place Q in that row,col
            grid[currRow][col] = 'Q';
            //call recursive function for next row
            nQueen(currRow+1,n,grid);
            //always revert the condition for next configration
            grid[currRow][col] = '.';
        }
    }
}
int main(){
    int n = 4;
    vector<vector<char>>grid(n, vector<char>(n, '.'));
    nQueen(0,n,grid);
    return 0;
}