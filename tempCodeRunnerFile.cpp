#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int beautifulArray(int arr[], int n){
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0;i<n;i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max - min;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int value = beautifulArray(arr,n);
    cout<<value<<endl;
    return 0;
}