/*
ALGORITHM
test case 1: 100 80 60 70 60 75 85
 TO FIND: span = how many elments are grater in its preV indexes includeing itself
LOGIC;
find the index of prev greater elment and subtract it with index of current element

*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//next greater element
vector<int> pge(vector<int> &arr){
    int n = arr.size();
    reverse(arr.begin(),arr.end());//
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            output[st.top()] = n - i - 1;//on reversing our index will also changed
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  //not mandotary
        output[st.top()] = -1;
        st.pop();
    }
    reverse(output.begin(),output.end());//reversing the output
    reverse(arr.begin(),arr.end());//to normalize the array
    return output;//store the indexes
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
        cout<<i-res[i]<<" ";//subracting the index of curr element and prex greater element
    }
    return 0;
}