/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int allPeaks(vector<int>arr,int low,int hi){
    int n = arr.size();
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(mid == 0){
            if(arr[mid]>arr[mid+1]) return 0;
            else return 1;
        }
        else if(mid == n-1){
            if(arr[mid] > arr[mid - 1]) return n -1;
            else return n - 2;
        }
        else{
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                return mid;
            }else if(arr[mid] > arr[mid - 1]){
                low = mid + 1;
            }else{
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
    for(int i= 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<allPeaks(arr,0,n-1)<<endl;
    
    return 0;
}