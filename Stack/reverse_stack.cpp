#include <iostream>
#include <stack>
using namespace std;

void InsertAtBottom(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    InsertAtBottom(st,x);
    st.push(curr);
}

void reverse(stack<int> &st){
    if(st.empty()) return;
    int curr = st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st,curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // stack<int> res = InsertAtBottom(st,100);
    reverse(st);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}
