#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int precedence(char ch){
	if(ch == '^') return 3;
	if(ch == '*' || ch == '/') return 2;
	if(ch == '+' || ch == '-') return 1;
	return -1;
}

string infixToPostfix(string exp){
	// Write your code here
	string result = "";
	stack<char> st;
	for(int i = 0;i<exp.size();i++){
		char ch = exp[i];
		if(isalpha(ch) || isdigit(ch)){
			result += ch;
		}
		else if(ch == '('){
			st.push(ch);
		}
		else if(ch == ')'){
			while(st.top() != '('){
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			// if(st.empty()) st.push(ch);
			while((!st.empty()) && (precedence(ch) <= precedence(st.top()))){
				result += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	while(!st.empty()){
		result += st.top();
		st.pop();
	}
	return result;
}
int main(){
    
    return 0;
}