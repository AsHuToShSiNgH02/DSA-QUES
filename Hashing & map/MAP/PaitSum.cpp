#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int>sumPair(vector<int> &v,int targetSum){

    unordered_map<int,int>m;
    vector<int> ans(2,-1);

    for(int i = 0;i<v.size();i++){
        if(m.find(targetSum-v[i])!=m.end()){    //chking if 13 - v[i] presemt in map
            ans[0] = m[targetSum-v[i]];//storing idx(value) of key(13-v[i]) in vector ans[0]
            ans[1] = i;//storin idx of current element in ans[1];
            return ans;
        }else{
            m[v[i]] = i; //if not present then mapping element with its idx;
        }
    }
}

int main(){
    int n; // 7
    cin>>n;
    vector<int> arr(n); //[1 4 5 11 13 10 2]

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    int targetSum; //13
    cin>>targetSum;
    
    vector<int> ans = sumPair(arr, targetSum);
    cout<<ans[0]<<","<<ans[1];

    return 0;

}