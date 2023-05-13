/*
ALGORITHM:
        idx: 0 1 2 3 4  5 6 7  8  9  10
test case 1: 4,6,3,1,0, 9,5,6, 7, 3, 2
     output: 6 9 9 9 9 -1 6 7 -1 -1 -1 
step 1->intialize stack to store idx
step 1->initialize output vector with same size of given arr and all idx -1
step 2-> push(0) in stack
step 3-> iterate for idx i to n-1
step 4-> chk st.empyt()? and arr[i]> arr[st.top()]
         step 1-> output[st.top()] == arr[i]
         step 2->pop the top
step 5-> push i so that it idx can be filled*/
/*
T.C. = O(n)
S.C. = O(n)
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//next greater element
vector<int> nge(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> output(n, -1);
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
    return output;
}
//next smaller element
vector<int> nse(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> output(n, -1);
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  //not mandotary
        output[st.top()] = -1;
        st.pop();
    }
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
    
    vector<int> res = nge(v);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    vector<int> resl = nse(v);
    for(int i = 0;i<resl.size();i++){
        cout<<resl[i]<<" ";
    }

    return 0;
}