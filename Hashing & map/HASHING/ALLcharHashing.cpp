// ************ALL CHAR-HASHING**************

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    int hash[256] = {0};//ascii code has 256 charactor (applicable for all char prsnt in ASCII table)
    for(int i = 0;i<s.size();i++){
        hash[s[i]]++;//increase the counting of evry mapped indx
        //ex: a will be mapped at 97th idx bcoz ascii value of a is 97
        
        //hash[s[i] - 'a']++  //in case of only lower case (then hash arr will be of size only 26)
    } 

    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        char x;
        cin>>x;
        cout<<hash[x]<<endl;//enabling hash
        //cout<<hash[x-'a']<<endl; //in case of only lower case or upper case
    }

    return 0;
}