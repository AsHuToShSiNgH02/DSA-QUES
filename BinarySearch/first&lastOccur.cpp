/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int> &v, int low,int hi,int target){
    int ans = -1;
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(v[mid] > target){
            ans = mid;
            hi = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int firstOccurence(vector<int> &v,int low,int hi,int target){
    int ans = -1;
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(target <= v[mid]){
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
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    int target;
    cin>>target;
    vector<int>ans;
    int a = firstOccurence(arr,0,n-1,target);
    if(a != target){
        arr.push_back(-1);
        arr.push_back(-1);
    }else{
        int b = lastOccurence(arr,0,n-1,target);
        arr.push_back(a);
        arr.push_back(b-1);
    }
    

    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}