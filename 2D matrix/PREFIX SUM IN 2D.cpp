#include <iostream>
#include <vector>
using namespace std;

int toSolve(vector<vector<int>>a,int l1,int l2,int r1,int r2){
    int n = a.size() , m = a[0].size();
    //converting vector into prefix sum coloumn wise
    // prefic sum [1,2,3,4] = [1,3,6,10]
    for(int i = 0;i<n;i++){
        for(int j = 1;j<m;j++){
            a[i][j] += a[i][j -1];
        }
    }
    int ans = 0;
    //finding row wise sum within given range and then adding them alltogether 
    for(int i = l1;i<=l2;i++){
        //arr[1,2,3,4] = prefix sum [1,3,6,10] now want sum of indices from 1 to 2 then arr[2] - arr[1-1] = 6 -1 =5
        ans += a[i][r2] - (r1 >= 1 ? a[i][r1 -1] : 0);  
    }
    return ans;
}
int main(){
    int row,col,l1,l2,r1,r2;
    
    cout<<"enter the row number"<<endl;
    cin>>row;

    cout<<"enter the col number"<<endl;
    cin>>col;

    cout<<"enter the edges to calculate the sum l1,l2,r1,r2"<<endl;
    cin>>l1>>l2>>r1>>r2;

    vector<vector<int>>arr(row,vector<int>(col));
    cout<<"enter the elements in vector : ";
    for(int i = 0;i<row;i++){
        for(int j = 0;j< col;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"sum is : "<<toSolve(arr,l1,l2,r1,r2)<<endl;
}