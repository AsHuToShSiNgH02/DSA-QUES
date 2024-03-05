#include <iostream>
#include <vector>
#include <queue>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        int fo = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) qu.push({i, j}); //multisource bfs
            }
        }
        qu.push({-1, -1});
        int mins = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            
            if(cell.first == -1 && cell.second == -1){
                mins++;
                if(not qu.empty()){
                    qu.push({-1, -1});
                }else{
                    break;
                }
            }else{
                int i = cell.first;
                int j = cell.second;
                for(int d = 0;d<4;d++){
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
                    if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)continue;
                    if(grid[nr][nc] == 2 || grid[nr][nc] == 0)continue;
                    fo--;
                    grid[nr][nc] = 2;
                    qu.push({nr, nc});
                }
            }
        }
        return (fo == 0) ? mins - 1: -1;
    }
};

int main(){
    
    return 0;
}