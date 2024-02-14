#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;
string postToInfix(string postfix) {
    // Write your code here.
    stack<string> st;
    for(int i = 0;i<postfix.size();i++){
        char ch = postfix[i];
        if(isalpha(ch)){
            st.push(string(1,ch));
        }else{
            string val2 = st.top();
            st.pop();

            string val1 = st.top();
            st.pop();

            string result = '('+val1+ch+val2+')';
            st.push(result);
        }
    }
    return st.top();
}
int main(){
    
    return 0;
}