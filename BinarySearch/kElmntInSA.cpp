/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int findTarget(vector<int> &arr,int low,int hi,int target){
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(arr[mid] == target) return mid;
        if(arr[mid] >= arr[low]){
            if(target<=arr[mid] && target>=arr[low]){
                hi = mid -1;
            }else{
                low = mid + 1;
            }
        }else{
            if(target>=arr[mid] && target <= arr[hi]){
                low = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
    }
    return -1;
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
    
    int a = findTarget(arr,0,n-1,target);
    cout<<a;

    return 0;
}