#include <iostream>
using namespace std;

bool find(int arr[],int n,int k,int i){
    if(i==n) return false;
    return (arr[i]==k)? true:find(arr,n,k,i+1);
}
int main(){
    int n = 1;
    int arr[1] = {4};
    int k = 4;
    bool c = find(arr,n,k,0);
    if(c){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}