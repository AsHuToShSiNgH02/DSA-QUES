/*Check whether two Strings are isomorphic of each other.Return true if they
are else return false*/
/*isomorphic strings (aab  xxy)*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

bool ChkOneToOneMapping(string a,string b){

    unordered_map<char,char>m;//<char of a, mapped char of b>

    for(int i = 0;i<a.size();i++){
        if(m.find(a[i])!=m.end()){ //if char of string 'a' present in map
            if(m[a[i]] != b[i]){ //if present then is it mapped with same key(char of b) or not
                return false;
            }
        }else{
            m[a[i]]=b[i]; //if not present then map it with corresponding key (char of b)
        }
    }
    return true;
}
bool isIsomorphic(string x,string y){

    if(x.length() != y.length()){
        return false;
    }

    //chking one to one mapping from a to b
    bool atob = ChkOneToOneMapping(x,y);

    //chking one to one mapping from b to a
    bool btoa = ChkOneToOneMapping(y,x);

    return atob && btoa;

}
int main(){
    string x;//aab
    cin>>x;
    string y;//xxy
    cin>>y;
    
    cout<<(isIsomorphic(x,y)?"YES":"NO");

    return 0;
}