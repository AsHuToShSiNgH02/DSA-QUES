#include <iostream>
#include <vector>
using namespace std;

void subset(int *arr,int n,int i,int sum,vector<int>&result){
    if(i==n){
        result.push_back(sum);
        return;
    }
    subset(arr,n,i+1,sum+arr[i],result);//pickup ith element
    subset(arr,n,i+1,sum,result);//donot picup iTH element
}
int main(){
    int n = 2;
    int arr[n]={2,4};
    vector<int>result;
    subset(arr,n,0,0,result);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}