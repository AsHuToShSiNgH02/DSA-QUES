/*
ALGORITHM:
case 1: {([])}{}
step 1-> iterating through string
step 2-> we will store all opening brackets in stack
step 3-> 1st closing bracket encountered will be compared with last opening bracket(top of stack)
step 4-> if closing bracket is of same type of opening bracket,pop the opening bracket from stack
step 5-> repeat the process and at end we will chk ,if stack is empty then string is balanced
as every opening brackets have found their closing brackets
*/
/*
T.C. = O(n)
S.C. = O(n)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i = 0;i<s.size();i++){
        char ch = s[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }else{
            //closing bracket
            if(ch == ')' && !st.empty() && st.top()== '('){
               st.pop();
            }else if(ch == ']' && !st.empty() && st.top()== '['){
               st.pop();
            }else if(ch == '}' && !st.empty() && st.top()== '{'){
               st.pop();
            }else{
               return false;
            }
        }
    }
    if(st.empty()){
        return true;  
    }
}

int main(){
    string s = "((()))";
    cout<<isValid(s)<<endl;

    return 0;
}