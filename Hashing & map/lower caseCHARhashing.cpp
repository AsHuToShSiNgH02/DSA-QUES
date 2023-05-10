// ************CHAR-HASHING***********

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    int hash[26] = {0};
    for(int i = 0;i<s.size();i++){
        hash[s[i] - 'a']++;
    } 

    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        char x;
        cin>>x;
        cout<<hash[x - 'a']<<endl;
    }

    return 0;
}