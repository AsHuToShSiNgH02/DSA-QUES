#include <iostream>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

int cal(int v1, int v2, char op){
    if(op == '^'){
        return pow(v1,v2);
    }
    if(op == '*'){
        return v1*v2;
    }
    if(op == '/'){
        return v1/v2;
    }
    if(op == '+'){
        return v1+v2;
    }
    return v1 - v2;
}
// posfix
// int eval(string &str){
//     stack<int> st;
//     for(int i=0;i<str.size();i++){
//         char ch = str[i];
//         if(isdigit(ch)){
//             st.push(ch - '0');
//         }
//         else{
//             int v2 = st.top();
//             st.pop();
//             int v1 = st.top();
//             st.pop();
//             st.push(cal(v1,v2,ch));
//         }
//     }
//     return st.top();
// }
//prefix
int eval(string &str){
    stack<int> st;
    for(int i= str.size()-1;i>= 0;i--){
        char ch = str[i];
        if(isdigit(ch)){
            st.push(ch - '0');
        }
        else{
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(cal(v1,v2,ch));
        }
    }
    return st.top();
}
int main(){
    string str = "-9+*132";//-9+*132
    cout<<eval(str);

    return 0;
}