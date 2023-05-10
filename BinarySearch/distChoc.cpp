/*
T.C. = O(n * log(∑arr[i]))
S.C. = O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool canDistChoc(vector<int> &arr,int mid ,int s){
    int n = arr.size();
    int stuReq = 1;
    int currSum = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] > mid) return false;
        if(currSum + arr[i] > mid){
            stuReq++;
            currSum = arr[i];
            if(stuReq > s) return false;
        }else{
            currSum += arr[i];
        }
    }
    return true;
}
int distChoc(vector<int> &arr, int s){
    int n = arr.size();
    int low = arr[0];
    int hi = 0;
    for(int i = 0;i<n;i++){
        hi += arr[i];
    }
    int ans = -1;
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(canDistChoc(arr,mid,s)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i= 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int s;
    cin>>s;

    cout<<distChoc(arr,s)<<endl;

    return 0;

}