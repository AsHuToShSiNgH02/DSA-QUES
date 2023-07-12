#include <iostream>
#include <vector>
using namespace std;

bool canWePlace(vector<vector<char>> &grid,int i,int j){
    //chking all position so that two knights dont cut each other
    if(i-1>=0 && j-2>=0 && grid[i-1][j-2]=='K') return false;
    if(i-2>=0 && j-1>=0 && grid[i-2][j-1]=='K') return false;
    if(i-1>=0 && j+2>=0 && grid[i-1][j+2]=='K') return false;
    if(i-2>=0 && j+1>=0 && grid[i-2][j+1]=='K') return false;
    return true;
}
void Kknight(int m,int n,vector<vector<char>> &grid,int k,int i,int j){
    //once count of k will be zero simpli print the configration
    if(k==0){
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        cout<<"***"<<"\n";
        return;
    }
    //when pointer reach to last coloumn,move on to first row of next coloumn
    if(j==n) return Kknight(m,n,grid,k,i+1,0);
    //when reach to last row then return
    if(i==m) return;
    //loop is to place same knights at diff position to make diff config
    for(int row = i;row < m;row++){
        //col will not always starts with j when row changes col starts from 0
        for(int col = (row == i? j : 0);col<n;col++){
            if(canWePlace(grid,row,col)){
                grid[row][col]='K';
                //each time knights will be subtracted and move further to next col
                Kknight(m,n,grid,k-1,row,col+1);
                //if configration is not possible then simply revert the condition
                grid[row][col]='_';
            }
        }
    }

}
int main(){
    int n =3,m = 3,k=5;
    vector<vector<char>> grid(m,vector<char>(n,'_'));
    Kknight(m,n,grid,k,0,0);
    return 0;
}