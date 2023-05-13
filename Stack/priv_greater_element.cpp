/*
ALGORITHM
step 1-> reverse the given array
step 2-> find the nxt greater element
step 3-> reverse the output
YOU'LL GET PREVIOUS GREATER ELEMENT
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//next greater element
vector<int> pge(vector<int> &arr){
    int n = arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  //not mandotary
        output[st.top()] = -1;
        st.pop();
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res = pge(v);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}