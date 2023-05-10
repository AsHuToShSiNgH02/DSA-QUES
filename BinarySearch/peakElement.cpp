/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> &arr,int low ,int hi){
    int ans = -1;
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(arr[mid - 1] < arr[mid]){
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
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int id = peakElement(arr,0,n-1);
    cout<<arr[id];

    return 0;
}