#include <iostream>
#include <stack>
using namespace std;

// stack<int> InsertAtBottom(stack<int> &st,int x){
//     stack<int> temp;
//     while(not st.empty()){
//         int curr = st.top();
//         st.pop();
//         temp.push(curr);
//     }
//     st.push(x);
//     while(not temp.empty()){
//         int curr = temp.top();
//         temp.pop();
//         st.push(curr);
//     }
//     return st;
// }

void f(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    f(st,x);
    st.push(curr);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // stack<int> res = InsertAtBottom(st,100);
    int x = 100;
    f(st,x);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}