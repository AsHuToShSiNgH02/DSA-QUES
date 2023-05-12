#include <iostream>
#include <stack>
using namespace std;

stack<int> InsertAtidx(stack<int> &st, int x, int idx){
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while(count < n - idx){
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    st.push(x);
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    return st;
    
}
int count = 0;
void f(stack<int> &st,int x,int idx,int n){
    if( count == n-idx){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    count++;
    f(st,x,idx,n);
    st.push(curr);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    int n = st.size();
    // stack<int> res = InsertAtidx(st,100,1,n);
    f(st,100,1,n);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}