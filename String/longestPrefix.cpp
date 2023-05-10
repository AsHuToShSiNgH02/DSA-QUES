/* 
T.C. = O(m * n)
S.C. = O(1)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longCommonPrefix(vector<string> &str){
    string s1 = str[0]; //keeping first string constant
    int ans_length = s1.size(); 

    for(int i = 1;i<str.size();i++){ //comparing first string with rest of the string 
        int j = 0; //iteratin to all genral string
        while(j<s1.size() && j<str[i].size() && s1[j] == str[i][j])
            j++;

            ans_length = min(ans_length,j); //min length b/w ans and j will be the length of common prefix 
        
    }
    string ans = s1.substr(0,ans_length);
    return ans;
}
int main(){
    int n;
    cout<<"no of string";
    cin>>n;

    cout<<"enter strings :";
    vector<string> str(n);
    for(int i = 0;i<n;i++){
        cin>>str[i];
    }
    
    cout<<"Longest common prefix : "<<longCommonPrefix(str);
    return 0;
}