/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int leastIndex(vector<int> &arr){
    if(arr.size() == 1) return arr[0];
    int low = 0, hi = arr.size()-1;
    if(arr[low] < arr[hi]) return low;

    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(arr[mid] > arr[mid + 1]) return mid + 1;
        if(arr[mid] < arr[mid - 1]) return mid;
        if(arr[mid] > arr[low]){
            low  = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0 ;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }


    cout<<leastIndex(arr)<<endl;
 
    return 0;
}