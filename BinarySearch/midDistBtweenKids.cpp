/*
T.C. = O(n*log(x₂ - x₁))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isMinDist(vector<int>&arr,int mid ,int s){
    int n = arr.size();
    int stuReq = 1;
    int lastPos = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i] - lastPos >= mid){
            stuReq++;
            lastPos = arr[i];
            if(stuReq == s){
                return true;
            }
        }
    }
    return false;
}
int minDist(vector<int>&arr,int s){
    int n = arr.size();
    int low = arr[0];
    int hi = arr[n-1] - low;
    int ans = -1;
    while(low <= hi){
        int mid = low + (hi - low)/2;
        if(isMinDist(arr,mid,s)){
            ans = mid;
            low = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int s;
    cin>>s;

    cout<<minDist(arr,s);

    return 0;
}