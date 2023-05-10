/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

bool findElmnt(vector<vector<int>> &arr,int target){
    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int hi = (n*m) - 1;
    while(low <= hi){
        int mid = low + (hi - low)/2;
        int x = mid/m;
        int y = mid % m;
        if(arr[x][y] == target){
            return true;
        }
        else if(arr[x][y] > target){
            hi = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr = {{1,3,5,7},{10, 11, 16, 20}, {23, 30, 34, 60}};

    int target;
    cin>>target;

    cout<<findElmnt(arr,target);

    return 0;
}