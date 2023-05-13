/*stack lect 2 last ques
MAX AREA HISTOGRAMS CAN MAKE
*/

#include <iostream>
#include <stack>
#include <limits.h>
#include <vector>
using namespace std;
//next smaller element
int Histogram(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    int ans = INT_MIN;
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            int el = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = (st.empty())? -1 : st.top();
            ans = max(ans, el*(nse - pse - 1));
        }
        st.push(i);
    }
    while(!st.empty()){  //not mandotary
        int el = arr[st.top()];
            st.pop();
            int nse = n;
            int pse = (st.empty())? -1 : st.top();
            ans = max(ans, el*(nse - pse - 1));
    }
    return ans;
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
    
    cout<<Histogram(v)<<endl;
    return 0;
}