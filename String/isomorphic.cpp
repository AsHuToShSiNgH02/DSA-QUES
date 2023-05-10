/* if word has one on one mapping
for ex: egg and icc here e<->i and g<->c
T.C. = O(n)
S.C. = O(256)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isIsomorphic(string s1,string s2){
    vector<int >freq1(126,0);
    vector<int >freq2(126,0);

    if(s1.length()!=s2.length()){
        return false;
    }

    for(int i = 0;i<s1.length();i++){
        if(freq1[s1[i]] != freq2[s2[i]]){//chking if value of char at idx i match in both vector
            return false;
        }
        freq1[s1[i]] = freq2[s2[i]] = i;//storint value of i in both the vectors 
    }
    
    return true;
    
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(isIsomorphic(s1,s2)){
        cout<<" isomaorphic";
    }else{
        cout<<" not isomorphic";
    }

    return 0;
}