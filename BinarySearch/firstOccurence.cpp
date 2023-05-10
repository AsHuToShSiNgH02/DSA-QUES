/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int>arr,int low,int hi,int target){
    int ans = -1;
    while(low <= hi){
        int mid = low + (hi - low)/2;
        if(target == arr[mid]){
            ans = mid;
            hi = mid - 1;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else{
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

    int target;
    cin>>target;

    cout<<firstOccurence(arr,0,n-1,target)<<endl;
    return 0;

}