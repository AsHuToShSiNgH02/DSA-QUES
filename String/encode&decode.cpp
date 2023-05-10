/*
T.C. = O(n) where n is length of result string
S.C. = O(n) where n is length of result string
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string decode(string s){
    string result = "";

    for(int i = 0;i<s.size();i++){

        if(s[i] != ']'){
            result.push_back(s[i]);
        }else{
            //extracting string
            string str = "";
            while(!result.empty() && result.back() != '['){
                str.push_back(result.back());
                result.pop_back();
            }
            //reverse string
            reverse(str.begin(),str.end());

            //removin opening bracket
            result.pop_back();
            
            //extracting num;
            string num = "";
            while(!result.empty() &&(result.back()>='0' && result.back() <= '9')){
                num.push_back(result.back());
                result.pop_back();
            }
            //reversing number 
            reverse(num.begin(),num.end());
            
            //converting num string to integer
            int int_num = stoi(num);
            
            //adding str int_num times into result
            while(int_num){
                result += str;
                int_num--;
            }

        }
    }
    return result;
}
int main(){
    string s;
    cin>>s;

    cout<<"decoded string : "<<decode(s);

    return 0;
}