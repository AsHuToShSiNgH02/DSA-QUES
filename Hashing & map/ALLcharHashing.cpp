// ************ALL CHAR-HASHING**************

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    int hash[256] = {0};
    for(int i = 0;i<s.size();i++){
        hash[s[i]]++;//increasing count for every mapped index
    } 

    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        char x;
        cin>>x;
        cout<<hash[x]<<endl;//enabling hash
    }

    return 0;
}