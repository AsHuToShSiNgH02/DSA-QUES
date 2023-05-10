#include <iostream>
#include <vector>
using namespace std;

int toSolve(vector<vector<int>>a,int l1,int l2,int r1,int r2){
    int n = a.size() , m = a[0].size();
    //prefix sum matrix row  wise
    for(int i = 0;i< n;i++){
        for(int j = 1;j<m;j++){
            a[i][j] += a[i][j -1];
        }
    }
    //prefix sum matrix coloumn wise
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            a[i][j] += a[i - 1][j];
        }
    }
    //printing prefix 2d matrix
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int top_sum = 0, left_sum = 0, top_left_sum = 0;
    if(l1 != 0) top_sum = a[l1 -1][r2];// sum above the req rectangle
    if(r1 != 0) left_sum = a[l2][r1 -1];//sum left side of req triangle
    if(l1 != 0 && r1 != 0) top_left_sum = a[l1 -1][r1 -1];// sum of commom area within top_sum anf left_sum

    int sum = a[l2][r2] - top_sum - left_sum + top_left_sum; // sum of required rectangle
    return sum;
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