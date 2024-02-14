#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

string preToPost(string s) {
    // Write Your Code Here
    stack<string> st;
    for(int i = s.size()-1;i>=0;i--){
        char ch = s[i];
        if(isalpha(ch)){
            st.push(string(1,ch));
        }else{
            string val1 = st.top();
            st.pop();

            string val2 = st.top();
            st.pop();

            string result = val1 + val2 + ch;
            st.push(result);
        }
    }
    return st.top();
}

int main(){
    
    return 0;
}