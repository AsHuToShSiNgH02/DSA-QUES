#include<bits/stc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for (char digit : num) {
            while (!stk.empty() && stk.top() > digit && k > 0) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }
        
        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        
        int start = 0;
        while (start < result.length() && result[start] == '0') {
            start++;
        }
        
        return start == result.length() ? "0" : result.substr(start);
    }
};

int main(){
    
    return 0;
}