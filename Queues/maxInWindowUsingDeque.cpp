int main(){
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxWindow(vector<int> &arr, int k){
    vector<int> res;
    deque<int> dq;
    for(int i = 0;i<k;i++){
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    for(int i = k;i<arr.size();i++){
        int curr = arr[i];
        if(dq.front() == (i-k)) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
}
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
     
    vector<int> res = maxWindow(arr,k);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}